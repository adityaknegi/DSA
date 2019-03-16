#include <stdio.h>
#include <stdlib.h>


struct queue
{
	int data;
	struct queue *next;

}*front=NULL,*rear=NULL;



void display(){

		struct queue *tem;
		tem=front;
		while(tem!=rear) // camparing addresss 
		{
			printf(" %d ", tem->data);
			tem=tem->next;
		}
		printf(" %d \n", tem->data);


}


void enqueued(int iteam){
	struct queue *teamp= (struct queue*)malloc(sizeof(struct queue));
         teamp->data=iteam;
         if(front==NULL&&rear==NULL){  // starting 
         	teamp->next=teamp;
         	rear=teamp;
         	front=teamp;
         }
         else{
         	rear->next=teamp;    
         	teamp->next=front;
         	rear=teamp;
         	      

         }
          display();
  
}


void dequeued(){
	if(front==NULL){  // if queue is empty 
		printf("no iteam to remove EMPTY queue");
		return ;
	}
	if(front==rear){
		front=NULL;
		 rear=NULL;
		 printf(" NOW QUEUE IS EMPTY ");
		 return ;

	}
	struct queue *p=front;
	rear->next=front->next;
	front=front->next;
	free(p);
	display();




}

int main(){

while(1){
		printf("Enter 1 for  enqueued to queue\n");
		printf("Enter 2 for  dequeued from queue\n");
		printf("Enter 3 for  front iteam and rear iteam :\n");
		printf("Enter 4 for exit \n");
		int c;
		scanf("%d",&c);

		switch(c){
			case 1:
			         printf("Enter iteam \n  ::");
			         int iteam;
			         scanf("%d",&iteam);
			         enqueued(iteam);
			         break;

			case 2:
			         dequeued();
			         break;

			case 3: 
			      //  rear_front(queue);
			        break;

			case 4:
			       exit(1);


			default : printf("wrong key \n");;
		}
	}

}