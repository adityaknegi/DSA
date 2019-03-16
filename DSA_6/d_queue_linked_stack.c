#include <stdio.h>
#include <stdlib.h>


struct queue {

  int data;
  struct queue *next;
  struct queue *pre;
} *f,*r;


void display(){

	struct queue * list=f;

	while(list){
		printf("  %d  ",list->data );
		list=list->next;
	}


	return ;
}



void insert_front(int iteam){

          struct queue *teamp=(struct queue*)malloc(sizeof(struct queue));

          teamp->data=iteam;
          teamp->next=f;
          teamp->pre=NULL;
          f=teamp;
          if(r==NULL)
          	r=teamp;
          display();
}

void insert_rear(int iteam){

	  struct queue *teamp=(struct queue*)malloc(sizeof(struct queue));
	  if(r==NULL){
       insert_front(iteam);
       return;
	  }
	  else{
	  	teamp->next=NULL;
	  	teamp->data=iteam;
	  	teamp->pre=r;
	  	r->next=teamp;
	  	r=teamp;
	  	display();
	  }

}




void delete_front(){

  struct queue *rm=f;

  if(f==NULL){
  	printf("QUEUE IS EMPTY \n");
  	return ;
  }
  else{

  	f=f->next;
  	if(f)
  	f->pre=NULL;
  else
  	r=NULL;
  
  	free(rm);
  	display();
  }
}


void delete_rear(){

	struct queue *rm=r;
  
  if(r==NULL||f==NULL){
  	printf("QUEUE IS EMPTY \n");
  	return ;
  }
  else{
  	printf("%d\n ", r->pre->data );

  	r=r->pre;
  	if(r)
    r->next=NULL;
   else
   	f=NULL;
    free(rm);
    display();
  }

}






int main()
{

	f=NULL;
	r=NULL;
	int iteam;


while(1){


	printf("Enter 1 for insert_front \n");
	printf("Enter 2 for insert_rear \n");
	printf("Enter 3 for delete_front\n");
	printf("Enter 4 for delete_rear\n");
	printf("Enter 5 for display\n");
	printf("Enter 6 for exit\n");
	int c;
	scanf("%d",&c);

	switch(c){

		case 1:

          printf("Enter  value\n");
		      scanf("%d",&iteam); 
		      insert_front(iteam);
		      break;

		case 2:

          printf("Enter  value\n");
		      scanf("%d",&iteam); 
		      insert_rear(iteam);
		      break;
        case 3:
		      delete_front();
		      break;

		case 4:
		      delete_rear();
		      break;

		case 5: 
		       display();
		       break;

	    case 6:
	          return 0;
	          break;

	    default : break;

	}

}
	return 0;
}