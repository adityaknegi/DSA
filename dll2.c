#include <stdio.h>
#include <stdlib.h>



struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head;


// display numbers 
void display(){
	struct node *teamp;
	teamp=head;
	while(head!=NULL){
		printf(" %d ,", head->data);
		head=head->next;
	}
	head=teamp;
}


// INSERT DATA
void insert(int data){
		 struct node *teamp,*p;
		 teamp=(struct node*)malloc(sizeof(struct node));
		 teamp->data=data;

		 if(head==NULL){
		 	teamp->prev=NULL;
		 	teamp->next=NULL;
		 	//head->next=teamp;
		 	head=teamp;
		 	return ;
		 }
		 else{
		 	teamp=head;
		 	p=(struct node*)malloc(sizeof(struct node));
		    p->data=data;
		 	while(teamp->next!=NULL){
		 		teamp=teamp->next;
		 	}
		 	p->next=NULL;
		 	p->prev=teamp;
		 	teamp->next=p;
		 }
		 display();

}


void delete(int value){
	struct  node *teamp;
	teamp=head;
	while(head->data!=value){
      head=head->next;
	}

   if(head->prev==NULL){
   	head->next->prev=NULL;
   	head=head->next;
   	return ;
    }else if(head->next){

    	head->prev->next=head->next;
    	head->next->prev=head->prev;
    	free(head);
    	head=teamp;return ;
    }else{

    	head->prev->next=NULL;
    	free(head);
    	head=teamp;
    }
     display();



}




int main()
{	
	struct node* head = NULL;
	int num,c;
	while(1){
		printf("\n1 FOR INSERT \n");
		printf("2 FOR DELETE \n");
		printf("3 for display\n");
		printf("4 for exit \n");
        scanf("%d",&c);

	switch(c){
       case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert(num);
                 break;
       case 2: 
                if(head==NULL)
                	printf("EMPTY LIST");
                    else {
                 printf("Enter the number to delete : ");
                 scanf("%d",&num);
                 delete(num);
                      }
       		 break;
                 
       case 3:     if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                printf("Element(s) in the list are : ");
              
                display();
                }
                break;
                
        

         case 4:     return 0;
        default:    printf("Invalid option\n");
       
    }
   
}
    return 0;

}




	
