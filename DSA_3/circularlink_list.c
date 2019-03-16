#include <stdio.h>
#include <stdlib.h>



struct node
{
	int data;
	struct node *next;
}*head;


void display(){

  	struct  node *teamp;
  	teamp=head;
  	while(head->next!=teamp){
  		printf("%d , ", head->data );
  		head=head->next;
  	}
  	  		printf("%d , ", head->data );

  	head=teamp;



}


void insert(int data){
	struct  node *teamp;
	teamp=(struct node*)malloc(sizeof(struct node));
	teamp->data=data;
	if(head==NULL){
		teamp->next=teamp;
		head=teamp;
	}else{
		struct node *teampvalue;
		teampvalue=head;
		while(head->next!=teampvalue){
			head=head->next;
		}
		head->next=teamp;
		teamp->next=teampvalue;
		head=teampvalue;


	}

	display();

}


void delete(int data){
	struct node *teamp;
	teamp=head;
	
	if(teamp==head->next){
		if(teamp->data==data){
			free(teamp);
			//free(teamp);

			head=NULL;
		}
		else
			printf("\n --------- value not exit -------------- \n");
		
		display();
		return ;
	}
	teamp=teamp->next;

	while(teamp!=head){
		if (teamp->next->data==data)
		{
			if(teamp->next==head) // number is head
			    head=teamp->next->next;
			    teamp->next=teamp->next->next;
			    display();
			    return ;
		}
		teamp=teamp->next;
	}

	printf("value not exit \n");
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

                 printf("Enter the number to delete : ");
                 scanf("%d",&num);
                 delete(num);

            
       case 3:     if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                printf("Element(s) in the list are : ");
                }
                display();
                break;
                
        

         case 4:     return 0;
        default:    printf("Invalid option\n");
       
    }
   
}
    return 0;

}