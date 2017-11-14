#include<stdio.h>
#include<stdlib.h>



struct node {

int value;
int height;
struct node *left;
struct node *right;
   // update height according to  height

}*root =NULL;




void inorder(struct node * root){
 if(root==NULL)
 	return ;
 else{
     inorder(root->left);
     printf("%d ",root->value );
     inorder(root->right);
     } 

   }



struct node *newnode(int key){

   struct node *teamp=(struct node*)malloc(sizeof(struct node));

   teamp->value=key;
   teamp->left=NULL;
   teamp->right=NULL;
   teamp->height = 1;
   return teamp;


}


int  h(struct node *node){
	if(node==NULL){
		return 0;
	}
	else
		return node->height;



}

int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;


}

int avlbalance(struct node *node ){
	if(node==NULL)
		return 0;

	return h(node->left) - h(node->right);
}

// left rotation 
struct node * left_rotation(struct node *node ){


	struct node *r=node->right,*r_l=r->left;



	r->left=node;
	node->right=r_l;

	// update height of new node place // r and node

	node->height=max(h(node->left),h(node->right))+1;
	r->height=max(h(r->left),h(r->right))+1;



	return r;

}

// right rotataion

struct node * right_rotation(struct node *node){


	struct node *l=node->left,*l_r=l->right;

	l->right=node;
	node->left=l_r;


	node->height=max(h(node->left),h(node->right))+1;
	l->height=max(h(l->left),h(l->right))+1;

	return l;
}


// insert element in AVL TREE
struct node *insert(struct node *node, int key){

  // normal bst insertion
   if(node==NULL)
   	return  newnode(key);

   if(key<node->value)
   	 node->left=insert(node->left,key);
   else if(key>node->value)
   	 node->right=insert(node->right,key);
   	else{ // key is unquie in bst 
   		printf("key allready present \n");
   	   		return node;
   	   	} 
      

    // update height


   	 node->height=1+max(h(node->left),h(node->right));
    
    //Get  balance factor value 

     int balance=avlbalance(node);

     
     // if blance factore change 

    
     // LEFT LEFT CASE


     if(balance>1 && key>node->left->value)
        return right_rotation(node);

    printf("hh\n");

     //RIGHT RIGHT CASE
     if(balance<-1 && key<node->right->value)
     	return left_rotation(node);

     // LEFT RIGHT CASE

     if(balance>1&&key>node->left->value){
     	node->left=left_rotation(node->left);
     	return right_rotation(node);
     }



     //RIGHT LEFT CASE
     if (balance<-1 && key<node->right->value)
     {
     	node->right=right_rotation(node->right);
     	return left_rotation(node);
     }
    

     return node;
}




                                                            //..........................................DELETION...................................................

// DELETE ELEMENT FROM AVL TREE

// FIST SIMPLE BINARY SEARCH TREE DELETION APPLY 
// THEN REBLANCING APPLY


// utility function 
struct node *min_value(struct node *node ){

   while(node->left){
   	node=node->left;
   }

   return node;



}

struct node *delete(struct node *node, int key){
	if(root==NULL){
		printf(".......................EMPTY TREE.................\n");
		return root;
	}


	if(node==NULL) //
		return node;

	// move left
	if(node->value>key)
		node->left=delete(node->left,key);
   // move right 
	else if(node->value<key)
    	node->right=delete(node->right,key);

    else{


    	// one child is NULL && node->value==key

    	if(node->left==NULL){      
    		struct node* t=node->right;
    		free(node);
    		return t;

    	}
    	else if(node->right==NULL){
   	 		struct node* t=node->left;
    		free(node);
    		return t;
    	}
    	// node with two child

    	struct node * teamp=min_value(node->right);
    	node->value=teamp->value;
    	// delete teamp which is inorder succesor 
    	node->right=delete(node->right,teamp->value);	
    }

      if(node==NULL)
      	return node;

      node->height=1+max(h(node->left),h(node->right));


      int balance=avlbalance(node);

      //....
      ...


}

int main(int argc, char const *argv[])
{
	
	int iteam;

	while(1){
		printf(" \n1. insert  \n 2. delete  \n 3. inorder  \n 4. search \n 5. bst or not 	9. exit    \n ");
		int c;
		scanf("%d",&c);


switch(c){

	case 1 : 
	        printf("Enter iteam to insert \n");
	        scanf("%d",&iteam);
	        root=insert(root,iteam);
	        printf("inorder sequence \n");

    	    inorder(root);
	        break;


	case 3:
	    printf("inorder sequence \n"); 
	    inorder(root);

        break;

	 case 2 : 

	       printf("delete iteam from tree\n");
	       scanf("%d",&iteam);
	       root= delete(root,iteam); // IMPORTANT TO UPDATE ROOT WHEN
	       printf("inorder sequence \n"); 
	    inorder(root);


	       break; 
/*

	case 3:
	    printf("inorder sequence \n"); 
	    inorder(root);
        break;


    case 4:
          printf("search ....\n");
          scanf("%d",&iteam);
          search(root,iteam);
          break;


    case 5:
          printf("Bstornot\n");
          if(Bstornot(root)){
          	printf("Yes\n");
          }
          else
          	printf("NOT\n");
          break;

          */

    case 9: return 0;

        }
     
         }
  

return 0;

      }

