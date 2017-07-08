#include <structs.h>

void initialize_user(struct _network *net,int index){
	
	int Nfriends=0;
	int num_purch=0;
	int i;
	
	
	//initialize the number of friends
	net->user[index].num_friends=Nfriends;	

	//initialize the array to hold friend ids
	/*net->user[index].friend_ids=malloc(Nfriends*sizeof(int *));
	for(i=0;i<Nfriends;i++)
		net->user[index].friend_ids[i]=calloc(2,sizeof(int));
	*/
	
	//initialize values for the mean, and std_dev of purchases in history
	net->user[index].mean=0.0;
	net->user[index].std_dev=0.0;
	
	//initialize the net id
	net->user[index].id=-1;
	net->user[index].anomolous=-1;
	net->user[index].recent=0.0;

	//allocate the array to hold purchaes
	net->user[index].num_purchases=num_purch;
	net->user[index].amount=calloc(num_purch,sizeof(double));

}
/*
void allocate_friend_array(struct _network *net, int index){

	int i;
	int Nfriends=net->user[index].num_friends;

	//reallocate the array
	net->user[index].friend_ids=(int **)realloc(net->user[index].friend_ids, Nfriends*sizeof(int *));
	for(i=0;i<Nfriends;i++) 
		net->user[index].friend_ids[i]=(int *)calloc(2,sizeof(int));

}*/

void allocate_user(struct _network *net){

	//reallocate user array

	int Nusers=net->Nusers;
	int index=Nusers-1;
	
	//net->user[index].friend_ids=realloc(Nfriends*sizeof(int *));
	//printf("Nusers=%d, %s\n",Nusers, __FILE__);
	

	//should reallocate the number of users structs 
	net->user=realloc(net->user,net->Nusers*sizeof(struct _user));
	//printf("net->user[%d].id=%d\n", index,net->user[index].id);
	//allocate_friend_array(net,index);
}
/*	
void isFriend(struct _network *net, int index1,int user2,int friend){

	int i;
	int Nfriends=net->user[index1].num_friends;
	int index2;

	//initially set index2 to -1
	index2=-1;

	//determine if the friend is already in the list
	for(i=0;i<Nfriends;i++){

		if(net->user[index1].friend_ids[i][0]==user2){
			index2=i;
			break;
		}
	}

	//if friend already in list, update the connection
	if(index2>-1){
		//set to friend or not if 
		if(friend>0){
			  net->user[index1].friend_ids[index2][1]=1;
		}
		if(friend<0){
			  net->user[index1].friend_ids[index2][1]=0;
		}
	}	
	//else, allocate new spot, and update the connection
	if(index2==-1){
		//allocate_friend_array(net, index1);
			
		//set to friend or not if 
		if(friend>0){
			  net->user[index1].friend_ids[Nfriends][1]=1;
		}
		if(friend<0){
			  net->user[index1].friend_ids[Nfriends][1]=0;
		}
	}

}*/

