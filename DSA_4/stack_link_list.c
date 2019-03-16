#include <stdio.h>
#include <stdlib.h>


struct stack{
	int data;
	struct stack *next;	

}*top=NULL;

void display(){
	struct stack *teamp;
	teamp=top;
	while(teamp!=NULL)
	{
		printf("%d ", teamp->data);
		teamp=teamp->next;
	}
	printf("\n");

}

void push(int iteam){
	struct stack *teamp=(struct stack*)malloc(sizeof(struct stack));
	teamp->data=iteam;
	if(top==NULL)
		teamp->next=NULL;
		
	else 
		teamp->next=top;
	
    top=teamp;
    display();

}

void pop(){
	if(!top){
		printf("Empty\n");
		return ;
	}

	struct stack *teamp;
	teamp=top;
	top=top->next;
	free(teamp);


 display();

}

int main(){
	while(1){
		printf("Enter 1 for  push\n");
		printf("Enter 2 for  pop\n");
		printf("Enter 3 for  display :\n");
		printf("Enter 4 for exit \n");
		int c;
		scanf("%d",&c);

		switch(c){
			case 1:
			         printf("Enter iteam \n  ::");
			         int iteam;
			         scanf("%d",&iteam);
			         push(iteam);
			         break;

			case 2:
			         pop();
			         break;

			case 3: 
			      //  rear_front(queue);
			         display();
			        break;

			case 4:
			       exit(1);


			default : printf("wrong key \n");;
		}



	}




}