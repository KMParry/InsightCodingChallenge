#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	
	int id1;
	int user1;
	int num_purch;

	double *amount;
	struct node *next;

};


struct edge
{
   int   id1;
   int   id2; 
   int user1;
   int user2;	
   struct edge *next;
};


typedef struct _graph{

	int vertexCount;
	int edgeCount;
	int top;

	struct edge *edge;	//linked list to hold edges
	struct node *node;	//linked list to hold nodes

	int *stack;	//array of ints holding IDs of users in the stack

} _GRAPH;

typedef struct _cutoff{
	
	int num_within;		//number of purchases within cutoff
	double *net_amount;	//array to hold each purchase within the cutoff

} _CUTOFF;

typedef struct _user{
	
	int id;			//user id
	int num_friends;	//number of friends
	
	//struct to hold the purchase history
	int num_purchases;
	double *amount;		//array to hold purchases of user1

	//double **net_amount;	//array to purchases of the network within certain cutoff 
	//struct _cutoff *cut;
	
	double mean;		//mean of the purchase_cutoff last purchases
	double std_dev;		//std. dev. of the purchase_cutoff last purchases
	
	int anomolous;		//flag to determine if user has anomolous purchase history	
	double recent;	

} _USER;

typedef struct _network{
	
	int Nusers; 		//number of users in network
	
	int D; //degree of social network
	int T; // # consec. purchases made by user's network
	
	//file pointers to in/out files
	FILE *fp_batchlog;
	FILE *fp_streamlog;
	FILE *fp_flagged;	

	struct _user *user; 	//array to hold the user structs
	struct _graph graph;	


} _NETWORK;



