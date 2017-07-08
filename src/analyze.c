#include <structs.h>

void bfs_traverse(struct _network *net, int user1,int user2);

void breadth_first_search(struct node *list[], int vertices, int parent[],int level[]){

	struct node *temp;
	int i, par,lev, flag=1;

	lev=0;
	level[1]=lev;

	while(flag){
		flag=0;
		for(i=1;i<=vertices;++i)
		{
			if(level[i]==lev){
				flag=1;
				temp=list[i];
				par=i;

			
				//serach the list
				while(temp!=NULL){
					if(level[temp->id1] !=-1){
						temp=temp->next;
						continue;

					}
				level[temp->id1]=lev+1;
				parent[temp->id1]=par;
				temp=temp->next;
				}
			}
		}

	++lev;

	}
}


void BFS_algorithm(struct _network *net,int D, int T){

	/* perform Breadth-first search of the linked list
	*  out to level D; for each parent vertex
        *  search user[index2] and then aggregate their 
        *  purchases and calculate mean and std. dev.  		*/

	//int val, front =0, rear=-1;
	int i,j,v1,v2,d;
	int vertices=net->graph.vertexCount; 	//these are the vertices
	int edges=net->graph.edgeCount;
	
	//index values are not passed properly to the node list
	printf("node count=%d, edge  count =%d\n\n", vertices, edges);
	//printf("net->graph.edge[0].user1=%d\n",net->graph.edge[0].user1);
	//printf("net->graph.edge[0].user2=%d\n",net->graph.edge[0].user2);
	//printf("net->graph.edge[1].user1=%d\n",net->graph.edge[1].user1);
	//printf("net->graph.edge[1].user2=%d\n",net->graph.edge[1].user2);
	//printf("net->graph.edge[2].user1=%d\n",net->graph.edge[2].user1);
	//printf("net->graph.edge[2].user2=%d\n",net->graph.edge[2].user2);

	//bfs_traverse(net, 1,2);
	
	
	struct node *adjacency_list[vertices+1];
	
	//for every vertex, will 
	int parent[vertices+1];
	int level[vertices+1];

	//initialize arrays
	for(i=0;i<=vertices;++i){
		adjacency_list[i]=NULL;
		parent[i]=0;
		level[i]=-1;
	}
	
	/*for(i=1;i<=edges;++i){
		v1=net->graph.edge[i].user1;
		v2=net->graph.edge[i].user2;
		
		//printf("v1=%d,v2=%d\n", v1,v2);
		//adjacency_list[v1]=create_node(adjacency_list[v1],v2);
		//adjacency_list[v2]=create_node(adjacency_list[v2],v1);
	}*/
}

void print_flagged(struct _network *net){

	int i;
	
	net->fp_flagged=fopen("flagged_purchases.json","w");		
	//fprintf(net->fp_flagged,"testing...\n");
	
	for(i=0;i<net->Nusers;i++){


		if(net->user[i].anomolous==1){
			fprintf(net->fp_flagged,"{\"event_type\":\"purchase\", \"timestamp\":\"2017-06-13 11:33:02\", \"id\": \"");
			fprintf(net->fp_flagged,"%d\", \"amount\": \"%lf\", \"mean\": \"%lf",net->user[i].id,net->user[i].recent,
				net->user[i].mean);
			fprintf(net->fp_flagged,"\", \"sd\": \"%lf\"}",net->user[i].std_dev);

		}

	}	

}

