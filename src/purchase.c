#include <structs.h>


void allocate_purchase(struct _network *net, int index){
	
	/* reallocate the purchase array
	*  based on the number of purchases */
	int num_purch=net->user[index].num_purchases;
	
	net->user[index].amount=realloc(net->user[index].amount,num_purch*sizeof(double));
	//printf("user index =%d has made %d purchases\n", index, num_purch);
}


void add_purchase(struct _network *net, int index,double add){

	/*  add purchase to the user purchase array */

	int num_purch=net->user[index].num_purchases;
	
	net->user[index].amount[num_purch-1]=add;
	//printf("number of purchases=%d for user1=%d, index =%d, of amount=%lf\n",
	//		num_purch, net->user[index].id,index,net->user[index].amount[num_purch-1]);

}

void check_recents(struct _network *net, int index, double purch){

	double mean, std_dev;
	int anomolous;
	double test;
	
	//check if recent purchase is anomolous
	mean=net->user[index].mean;
	std_dev=net->user[index].std_dev;
	
	test=mean+(3*std_dev);
	if(purch>test) net->user[index].anomolous=1;
	if(purch<=test) net->user[index].anomolous=0;

}

/*
int calculate_mean_std_dev(struct _network *net, int index, int T){

	int i,count=0;
	int num_purch=net->user[index].num_purchases;
	double mean=0.0,std_dev=0.0,element;
	
	printf("num_purch=%d\n",num_purch);
		
	if(num_purch<2){
		printf("not enough purchases to consider...\n");
		return 0;
	
	}
	//want to loop over the last T purchases
	for(i=num_purch-1;i>num_purch-1-T;i--){
		
		count++;
		if(i<0) break;
		printf("for i=%d, count=%d,amount=%lf\n", i,count,net->user[index].amount[i]);
		mean+=net->user[index].amount[i];
	}
	//printf("mean=%lf\n",mean);

	for(i=num_purch-1;i>num_purch-1-T;i--){
		if(i<0) break;
		element=net->user[index].amount[i]-mean;
		std_dev+=element*element;	
	}
	
	if(num_purch<T){
		printf("there are less purchases than the cutoff\n");
		mean=mean/count;
		std_dev=std_dev/count;
		std_dev=sqrt(std_dev);
	}
	if(num_purch>T){
		printf("take the whole set of T purchases...\n");
		mean=mean/T;
		std_dev=std_dev/T;
		std_dev=sqrt(std_dev);
	}
	
	printf("std_dev=%lf\n", std_dev);
	
	//net->user[index].mean=mean;
	//net->user[index].std_dev=std_dev;
	return 1;

}*/
