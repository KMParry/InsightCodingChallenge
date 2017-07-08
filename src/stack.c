#include <structs.h>

//function declarations 
void allocate_user(struct _network *net);
void initialize_user(struct _network *net, int index);
void initialize_edge_structs(struct _network *net);


// list.c functions
struct edge* create_edge(int index1, int user1,int index2,int user2);
struct node* create_node(int index1, int user1);

void Edge_prependItem(struct edge ** headRef, struct edge* newItem);
void Edge_deleteItem(struct edge** headRef, int user1, int user2);

void Node_prependItem(struct node ** headRef, struct node* newItem);
void Node_deleteItem(struct node** headRef, int user1);

int isDuplicate(struct _network *net, int user1){

        /*      checks to see if the user1 is already   *
        *       in the stack; if duplicate, returns     *
        *       index of user1, else returns -1         */

        int i,duplicate;
        int size=net->graph.vertexCount;

        //initialize duplicate to -1
        duplicate=-1;

        //loop through stack to see if user1 is in the stack
        for(i=0;i<size;i++){

                if(user1==net->graph.stack[i]){
                        duplicate=i;
                        break;
                }
        }

        return duplicate;
}

void allocate_stack(struct _network *net){

        /*   reallocates stack with each new vertex 		*
        *    and increments the number of users in the network  *
        *    and allocates and initializes new users		*/

        int size=net->graph.vertexCount;

        if(size>0){

                net->graph.stack=realloc(net->graph.stack,size*sizeof(int));

                //set to zero
                net->graph.stack[size-1]=0;
        }
        
	net->Nusers=size;

        allocate_user(net);
	initialize_user(net, size-1);
}

void add_to_stack(struct _network *net,int user1){
	
	/*    updates stack with new user index
	*     also updates user with the id number  */

        int size=net->graph.vertexCount;

        net->graph.stack[size-1]=user1;

	net->user[size-1].id=user1;
        //printf("net->graph.stack[%d]=%d\n", size-1, net->graph.stack[size-1]);

}

//void add_edge(struct _network *net, int index1,int index2){
void add_edge(struct _network *net, int index1, int user1, int index2, int user2){
	
	/*    create the edge in the linked list*/

	struct edge *p;

	//p=create_node(index1,index2);	
	p=create_edge(index1,user1,index2,user2);		
	Edge_prependItem(&(net->graph.edge), p);
	//printf("p->user1=%d,p->user2=%d\n", p->user1,p->user2);
	//printf("p->id1=%d,p->id2=%d\n", p->id1,p->id2);
	//printf("finished adding edge\n");
	net->graph.edgeCount++;
}

void add_node(struct _network *net, int index1, int user1){
	
	/*    create the edge in the linked list*/

	struct node *p;

	p=create_node(index1,user1);		
	Node_prependItem(&(net->graph.node), p);

	printf("p->user1=%d,p->id1=%d\n", p->user1,p->id1);
	//printf("finished adding edge\n");
	//net->graph.vertexCount++;
}


void remove_edge(struct _network *net,int index1, int index2){
	
	Edge_deleteItem(&(net->graph.edge),index1,index2);
	net->graph.edgeCount--;
}

