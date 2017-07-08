#include <structs.h>

void initialize_network(struct _network *net){
	
	int Nusers=0;

	//pass number of users to net struct
	net->Nusers=Nusers;
	
	//initialize the array of user structs
	net->user=malloc(Nusers*sizeof(struct _user));

}

void initialize_graph(struct _network *net){
	
	int i;
	
        //initialize count and end of stack indexes
        net->graph.vertexCount=0;
	net->graph.edgeCount=0; 
       //net->graph.top=-1;
	
	//these are all currently size 0xint arrays
        net->graph.stack=malloc(net->graph.vertexCount*sizeof(int));

}

