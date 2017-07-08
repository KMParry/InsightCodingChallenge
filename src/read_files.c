#include <structs.h>

void allocate_user(struct _network *net);
int isDuplicate(struct _network *net, int user1);
void allocate_stack(struct _network *net);
void add_to_stack(struct _network *net, int user1);
void allocate_purchase(struct _network *net,int index);
void add_purchase(struct _network *net, int index,double add);

void add_edge(struct _network *net, int index1, int user1, int index2, int user2);
void remove_edge(struct _network *net, int index1, int index2);

void add_node(struct _network *net, int index1, int index2);

int read_stream_file(char *input_filename,struct _network *net){

	/*							*
	* 	This function reads in the stream_file and	*				
	*	passes data to construct the recent purchase	*
	*	history           			        *
	*							*/		
	
	FILE *fp_stream=fopen(input_filename, "r");
	//FILE *fp_stream=fopen("stream_log.json", "r");

	char *line=malloc(512*sizeof(char));
	char col0[40],col4[40],col5[40],col6[40];
	
	double amount;	//purchase amount	
	int user1;	//user vertices
	int index1;

	//read in until end of the batch_log file	
	while(fgets(line,511,fp_stream)!=NULL){
		
		//parse line
		sscanf(line, "%s%*s%*s%*s%s%s%s",col0,col4,col5, col6);
	
		//extract user1 and amount of purchase
		sscanf(col4,"%*[^0123456789]%d%*[^0123456789]",&user1);
		sscanf(col6,"%*[^0123456789]%lf%*[^0123456789]",&amount);
	
		//find index of user, add to recent
		index1=isDuplicate(net, user1);
		if(index1>-1){
		
			net->user[index1].recent=amount;
		}
	}
	
	free(line);
	return 1;
}

int read_batch_file(char *input_filename,struct _network *net){

	/*							*
	* 	This function reads in the batch_file and	*				
	*	passes data for each user to the user struct	*
	*	calls functions to construct the graph          *
	*							*/		

	FILE *fp_batch=fopen(input_filename, "r");
	//FILE *fp_batch=fopen("batch_log.json", "r");

	char *line=malloc(512*sizeof(char));
	char col0[40],col4[40],col5[40],col6[40];
	
	double amount;	//purchase amount	
	int user1,user2;	//user vertices
	int index1,index2;	//index of user1, and user2 in the stack

	//get and assign values for D and T
	fgets(line,511, fp_batch);
	sscanf(line,"%*[^0123456789]%d%*[^0123456789]%d",&(net->D),&(net->T));	

	//read in until end of the batch_log file	
	while(fgets(line,511,fp_batch)!=NULL){
		
		//parse the json line
		sscanf(line, "%s%*s%*s%*s%s%s%s",col0,col4,col5, col6);
		
		//determine if this is a purchase line or not
		if(!(strncmp(col0,"{\"event_type\":\"purchase",20))){

			//hacky way to grab user1 and amount from parsed line
			sscanf(col4,"%*[^0123456789]%d%*[^0123456789]",&user1);
			sscanf(col6,"%*[^0123456789]%lf%*[^0123456789]",&amount);
			
			//printf("user1=%d made purchase of amount=%lf\n",user1,amount);
			
			//find index of user1 in stack; if not in stack, add it	
			index1=isDuplicate(net, user1);
			if(index1==-1){
				
				//increment the vertexCount
				net->graph.vertexCount++;
				
				allocate_stack(net);
				add_to_stack(net,user1);
				
				index1=net->Nusers-1;
				add_node(net,index1,user1);
			}

			//increment the number of purchases for this user
			net->user[index1].num_purchases++;	
			allocate_purchase(net, index1);
			add_purchase(net, index1,amount);


		}
		if(!(strncmp(col0,"{\"event_type\":\"befriend",20))){
			
			//hacky way to grab user1,user2 index from parsed line	
			sscanf(col4,"%*[^0123456789]%d%*[^0123456789]",&user1);
			sscanf(col6,"%*[^0123456789]%d%*[^0123456789]",&user2);
			
			//check to see if user1 or user2 is already in 
			//stack; if not, add to stack and vertex to graph
			index1=isDuplicate(net,user1);
			if(index1==-1){
				
				//increment the vertexCount
				net->graph.vertexCount++;
				
				//add vertex to stack
				allocate_stack(net);
				add_to_stack(net,user1);
	
				//update index to last element
				index1=net->Nusers-1;
				add_node(net,index1,user1);			
			}
			
			index2=isDuplicate(net,user2);
			if(index2==-1){
			
				//increment the vertexCount
				net->graph.vertexCount++;
				
				//add vertex to stack
				allocate_stack(net);
				add_to_stack(net,user2);
				
				//update index2 to last element
				index2=net->Nusers-1;
				add_node(net,index2,user2);			
				
			}

			//add edge between user1 (at index1) and user2 (at index2)
			add_edge(net,index1,user1,index2,user2);

			//printf("create friendship between user1=%d,user2=%d\n",user1,user2);
		}
		if(!(strncmp(col0,"{\"event_type\":\"unfriend",20))){
			
			//hacky way to grab user1,user2 index from parsed line	
			sscanf(col4,"%*[^0123456789]%d%*[^0123456789]",&user1);
			sscanf(col6,"%*[^0123456789]%d%*[^0123456789]",&user2);
			
			
			//find index in stack of user1,user2
			index1=isDuplicate(net,user1);
			if(index1==-1){
				
				//increment the vertexCount
				net->graph.vertexCount++;
				
				//add vertex to stack
				allocate_stack(net);
				add_to_stack(net,user1);
	
				//update index to last element
				index1=net->Nusers-1;
				add_node(net,index1,user1);			
			}
			
			index2=isDuplicate(net,user2);
			if(index2==-1){
			
				//increment the vertexCount
				net->graph.vertexCount++;
				
				//add vertex to stack
				allocate_stack(net);
				add_to_stack(net,user2);
				
				//update index2 to last element
				index2=net->Nusers-1;
				add_node(net,index2,user2);			
				
			}
			
			//delete edge between user1 (at index1) and user2 (at index2)
			remove_edge(net,index1,index2);	
			
			//printf("delete friendship between user1=%d,user2=%d\n",user1,user2);
		}
	}
	
	free(line);
	return 1;		

}
