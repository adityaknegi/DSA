#include <stdio.h>
#include <stdlib.h>


/*

In an XOR linked list, you store one 'pointer' per node, which is the XOR of prev and xor (or if one of them is absent, just the other (the same as XORing with 0)). The reason why you can still traverse an XOR linked list in both directions relies on the properties of XOR and the redundancy of information inherent in a double linked list.


*/
struct node {

	int data;
	struct node *xor; //XOR representation npx (XOR of xor and previous)

}*head;

struct node * xor(struct node * p, struct node *n){

	return (struct node*)((unsigned)p^(unsigned)n);
}
void display(){


  struct node *previous, *current, *next;
  previous = NULL;
  current = head;

  while(current)
  {
    //print data of current node
    printf(" %d ",current->data);

    next = xor(previous,current->xor);

    //update previous and current for next iteration
    previous = current;
    
    current = next;
  }

  printf("\n");
}

void insert(int data){
	struct node *teamp,*p;
	teamp=(struct node*)malloc(sizeof(struct node));
	
	teamp->data=data;
	 
	    teamp->xor= xor(NULL,teamp); // xor on addresss of address of 2 node 
    
    if (head!=NULL)
    {
    	struct node *teamp1=xor(NULL,head->xor);
    	teamp->xor=xor(teamp,teamp1);
    }


    head=teamp;
    display();

}


 
int main()
{	
	struct node* head = NULL;
	int num;
	while(1){
	        printf("Enter the number to insert : ");
	        scanf("%d",&num);
	        insert(num);
	        }

   

    return 0;

}