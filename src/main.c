#include <structs.h>

//function declarations
void initialize_graph(struct _network *net);
void initialize_network(struct _network *net);

int read_batch_file(char *input_filename,struct _network *net);
int read_stream_file(char *input_filename,struct _network *net);

void BFS_algorithm(struct _network *net, int D, int T);
void print_flagged(struct _network *net);

int main(int argc, char **argv)
{
	/*								*
	*	main runs the program to read in the various files	*
	*	and determine if if a user has an anomolous purchase	*
	*								*/
	
	int success;

	//check usage of the function
	if(argc!=3){ 
		printf("USAGE %s <batch_log.json> <stream_log.json>\n",
			argv[0]); exit(1);
	}

	struct _network net;

	//initialize the graph,network,user,purchase structures data structures
	initialize_graph(&net);	
	initialize_network(&net);

	//read in batch log file and construct the network
	success=read_batch_file(argv[1],&net);
	
	//search network using breadth-first search
	BFS_algorithm(&net, net.D, net.T);
	
	//read in stream log
	success=read_stream_file(argv[2],&net);

	//print flagged purchases
	//determine if purchase is anomolous from stream file
	print_flagged(&net);
	
	return 1;


}
