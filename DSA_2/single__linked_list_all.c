#include<stdio.h>
#include<stdlib.h> // memory allocation  

struct node {
   int data;
   struct node *next;

}*head;

void insert(int data){    
    if(head==NULL){
    	    head=(struct node *)malloc(sizeof(struct node));

			head->next=NULL;
			head->data=data; return ;}
     
    struct node *teamp,*prev,*place;
    teamp=(struct node *)malloc(sizeof(struct node));
    place=(struct node *)malloc(sizeof(struct node));
    prev=(struct node *)malloc(sizeof(struct node));
    prev =NULL; 
    teamp->data=data;
    place=head; // for move
	int n=0;
	// single node then 
				if(place->next==NULL){ // eample 2->NULL OR 3->NULL
                      if(data>place->data)
                      {	teamp->next=place;   // teamp->2->next;
                         head=teamp;
                        return ;}
                      else {
                      	teamp->next=NULL;
                      	place->next=teamp;
                      	head=place;return ;
                      }
                  }
	
    while(place->next!=NULL&&data<place->data){  // sort
				     n++;     // if we need to add at starting or elsewhere 
				     prev=place;
				     place=place->next; }

                 if(!n){
                 	teamp->next=head;
                 	head=teamp;

                 }
                                               
				if(place->next&&n>0) // check if one node exit or more  
				       { 
				     teamp->next=place;
				     prev->next=teamp;
				     		return ;		     
  				    }
				else if(place->next==NULL&&n>0){
					if(data>place->data)
                      {	teamp->next=place;   // teamp->2->next;
                         prev->next=teamp;
                        return ;
                      }
                     else     {    // data is largest 
                      	teamp->next=NULL;
                      	 place->next=teamp;
                      	return ;}
                    }
				
                                         
                                   
}

void display(){

    struct node *teamp;
    teamp=(struct node *)malloc(sizeof(struct node)); 
    teamp=head;

    while(teamp!=NULL){
     printf(" %d ",teamp->data);
        teamp=teamp->next;
     if(teamp!=	NULL)
     printf(" , ");

}
}

 void   delete(){
 
		
        struct node* next = head->next;
        free(head);
       head = next;
 }


void delete_nth(int n){

			    struct node *teamp;
			    teamp= (struct node*)malloc(sizeof(struct node));
			    teamp=head;
			    if(n==1){
			    head=head->next;
			    return;}
          while(teamp!=NULL&&n!=0){
			    n--;
			 if(n==1&&teamp->next->next){
			    teamp->next=teamp->next->next;
			    return;
			 }
			    if(n==1)
			    teamp->next=NULL;
			   
			    teamp=teamp->next;
	       }
			    
}


void reverse(){

    struct node* prev   = NULL;
    struct node* current = head;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
           
           
        head=prev;                                                                                                                                                                           
           

}



void delete_pointer_value(int data)
{
	 struct node *teamp;
			    teamp= (struct node*)malloc(sizeof(struct node));

	 teamp=head;
    while(teamp&&teamp->data!=data){
 	     teamp=teamp->next;
         //printf("%d",teamp->data);  // core dumpe when teamp ==NULL
 	 }

    if(teamp==NULL){ 
        printf("\n no such value in link list \n ");
 	        return ;
        }
 	  if(teamp->next==NULL)
 	  {
 	  	struct node* next=teamp;
 	  	head=NULL;
 	  	free(teamp);
 	  }

    while(teamp->next->next){
    	teamp->data=teamp->next->data;
        teamp=teamp->next;
    }
        teamp->data=teamp->next->data;
        struct node *next=teamp->next;
        teamp->next=NULL;
         
        free(next);
  
}



int  main()
{
    int i,num;
    struct node *n;
    head=NULL;
    while(1)
    {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("1.Insert\n");
    printf("2.Display\n");
    printf("3.Delete node\n");
    printf("4.Delete nth node\n"); //
    printf("5.Delete node where point is\n ");  /*2 ->3->4->5->null  suppose node is 3 is pointer then value of 4 insert to 3 and next value of 4 to 4 
    till bull we get     new link list is 2->4->5->null */
    printf("6.reverse \n"); //  take three node current next prev 
    printf("7.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert(num);
                 break;
                 
        case 2:     if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                printf("Element(s) in the list are : ");
                }
                display();
                break;
                
        case 3: if(head==NULL) 
                  printf("Empty list \n");
                 else
                 delete();
                break;
                
       case 4: if(head==NULL) 
                  printf("Empty list \n");
                 else
               {
                int p;
               printf("Enter n");
               scanf("%d",&p);
                delete_nth(p);
                }
                break;       
            

         case 5:
             if(head==NULL)
             	printf("Empty list");
             else
             {
             	printf("pointer at : ");
             	int data;
             	scanf("%d",&data);
             	delete_pointer_value(data);
             }
               break;  

         case 6:  if(head==NULL)
                printf("List is Empty\n");
                else
                reverse();
                break;

       case 7:     return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}
