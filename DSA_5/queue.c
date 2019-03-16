#include <stdio.h>
#include <stdlib.h>
// circluar queue

int front=0, rear=0 , capcity;

void display(int queue[]){
		int l=	front;
		while(l!=rear){
		l=(l+1)%capcity;
		printf("%d ",queue[l]);

		}
		printf("\n");
}

void enqueued(int iteam, int queue[]){
	rear=(rear+1)%capcity;
	if(rear==front){
		printf("queue overflow \n");
		if(front ==0){
			rear=capcity-1;
		}
		else
			rear=rear-1;
	}
	else
		queue[rear]=iteam;

	display(queue);
}


void dequeued(int queue[]){
	if(rear==front){

		printf("queue is empty\n");
		return;
	}
	else{
		display(queue);
		front=(front+1)%capcity;
		printf("delele queue[%d]=%d\n",front,queue[front] );
        display(queue);

	}
}

int main(int argc, char const *argv[])
{
	 
	scanf("%d",&capcity);

	int queue[capcity];

	while(1){
		printf("Enter 1 for  enqueued to queue\n");
		printf("Enter 2 for  dequeued from queue");
		printf("Enter 3 for  front iteam and rear iteam :\n");
		printf("Enter 4 for exit \n");
		int c;
		scanf("%d",&c);

		switch(c){
			case 1:
			         printf("Enter iteam \n");
			         int iteam;
			         scanf("%d",&iteam);
			         enqueued(iteam,queue);
			         break;

			case 2:
			         dequeued(queue);
			         break;

			case 3: 
			      //  rear_front(queue);
			        break;

			case 4:
			       exit(1);


			default : printf("wrong key \n");;
		}
	}

	return 0;
}