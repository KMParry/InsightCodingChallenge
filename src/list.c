#include <structs.h>
#include <stdlib.h>
#include <stdio.h>

struct node* create_node(int index1,int user1){
	
	struct node *newnode=malloc(sizeof(*newnode));
	if(newnode==NULL)
	{
		printf("\nMemory was not allocated.\n");
		return 0;
	}
	else{
		newnode->id1=index1;
		newnode->user1=user1;
		return newnode;	
	}

}


struct edge* create_edge(int index1,int user1, int index2,int user2)
{
	//struct edge *first=0;
	//struct edge *last=0;

	struct edge *newnode =malloc(sizeof(*newnode));
	if(newnode==NULL)	
	{
		printf("\nMemory was not allocated.\n");
		return 0;
	}
	else{
		newnode->id1=index1;
		newnode->id2=index2;
		newnode->user1=user1;
		newnode->user2=user2;
	

		return newnode;
	}
}

//Edge_delete removes item (pointer to item you want to delte)
void Edge_delete(struct edge *delete)
{
   free(delete);
}

void Node_delete(struct node *delete)
{
   free(delete);
}

void Edge_prependItem(struct edge ** headRef, struct edge* newItem) 
{ 
   newItem->next = *headRef;
   *headRef = newItem;
}

void Node_prependItem(struct node ** headRef, struct node* newItem) 
{ 
   newItem->next = *headRef;
   *headRef = newItem;
}


void Edge_deleteItem(struct edge** headRef, int user1, int user2)
{
 	struct edge *prev =0;
	struct edge *current= *headRef; 
	
	//if empty list, bail
   	if(current ==0) return;
 
	//check user ids of the vertices
   	while(current !=0 && !(current->user1 ==user1 && current->user2==user2) && !(current->user1==user2
		&& current->user2==user1))
	{	
	
		printf("current->user1=%d,user1=%d,current->user2=%d,user2=%d\n",
			current->user1,user1,current->user2,user2);	

		prev =current;
		current = current->next;
		
   	}	

  	 //not found in list,then return
   	if(current ==0){
		return;
  	 }
   
   	//special case if found node is the first node
   	if(prev==0){
   		//unlink by setting head pointer to null
		*headRef=current->next;
   	}
	else{

		//unline the node from previous node
		prev->next = current->next;
	}
	free(current);
}

//void Node_deleteItem(struct node** headRef, int index1)
void Node_deleteItem(struct node** headRef, int user1)
{
 	struct node *prev =0;
	struct node *current= *headRef; 
	
	//if empty list, bail
   	if(current ==0) return;
 
	//check user ids of the vertices
	//check this logic
   	//while(current !=0 && !(current->id1 ==index1))
   	while(current !=0 && !(current->user1 ==user1))
	{		

		prev =current;
		current = current->next;
   	}	

  	 //not found in list,then return
   	if(current ==0){
		return;
  	 }
   
   	//special case if found node is the first node
   	if(prev==0){
   		//unlink by setting head pointer to null
		*headRef=current->next;
   	}
	else{

		//unline the node from previous node
		prev->next = current->next;
	}
	free(current);
}


void bfs_traverse(struct edge** headRef, int user1, int user2)
{
 	struct edge *prev =0;
	struct edge *current= *headRef; 
	int n;
	
	//if empty list, bail
   	if(current ==0){
		printf("the list is empty!!\n");
		 return;
	}

	 
	//check user ids of the vertices
   	while(current !=0){
		printf("user1=%d,user2=%d\n", user1,user2);	

		if( !(current->user1 ==user1 && current->id2 ==user2)) printf("user1==id1,user2==id2\n");
		if( !(current->user1==user2 && current ->user2==user1)) printf("user1==id2,user2==id1\n");

		//prev =current;
		//current = current->next;
   	}	
	/*
  	 //not found in list,then return
   	if(current ==0){
		return;
  	 }
   
   	//special case if found node is the first node
   	if(prev==0){
   		//unlink by setting head pointer to null
		*headRef=current->next;
   	}
	else{

		//unline the node from previous node
		prev->next = current->next;
	}*/
	free(current);
	
}
