#include <stdio.h>
#include <stdlib.h>



struct queue
{
	int data;
	int priority;
	struct queue * next;
	/* data */
}*f,*r;

void display(){

	struct queue *list=f;


	while(list){

		printf("priorty,iiteam (%d,%d )) :: ",list->priority,list->data);
		list=list->next;

	}
	printf("\n");


	return ;
}


void insert(int iteam , int priority){

  struct queue *temp=(struct queue*)malloc(sizeof(struct queue));

  if(temp==NULL){

  	printf("Memory is not available :\n ");
  	return ;
  }

  temp->data=iteam;
  temp->priority=priority;

  if(f==NULL&&r==NULL){

  	temp->next=NULL;
  	f=temp;
  	r=temp;
  	display();
  	return ;
  }
  else{
  	struct queue *check,*pre=f;
  	check=f;

  	while(check->next!=NULL&&check->priority<=temp->priority){
          pre=check; 
         check=check->next;
        
  	}
  if(check->next==NULL){
       if(check->priority<=temp->priority)
  		{     temp->next=NULL;
            check->next=temp;
            r=temp;}
      else{
          temp->next=check;
           pre->next=temp;
      }

  		display();
  		return ;
  	}
  	else if(check==f){
      if(check->priority>=temp->priority)
  		{     temp->next=f;
            f=temp;}
      else{
        temp->next=NULL;
        f->next=temp;
        r=temp;
      }
  		display();
  		return ;
  	}

  	else  {
     

  		temp->next=check;
  		pre->next=temp;
  	 display();
  		return ;

  	}

  }
}

 void delete(){

 struct  queue *rem=f;
  if(f==NULL){
    printf("EMPTY QUEUE\n");
    return ;
  }

  f=f->next;
  free(rem);
  display();

 return ;
 }


 int main()
{

	f=NULL;
	r=NULL;
	int iteam,priority;


while(1){
	printf("Enter 1 for insert \n");
	printf("Enter 2 for delete\n");
	printf("Enter 3 for display");
	printf("Enter 4 for exit\n");
	int c;
	scanf("%d",&c);

	switch(c){

		case 1:

          printf("Enter priority && value\n");
          scanf("%d",&priority);
		      scanf("%d",&iteam); 
		      insert(iteam,priority);
		      break;

		case 2:
		      delete();
		      break;

		case 3: 
		       display();
		       break;

	    case 4:
	          return 0;
	          break;

	    default : break;

	}

}
	return 0;
}
