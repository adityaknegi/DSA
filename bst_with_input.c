#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct node {

int value;
struct node *left;
struct node *right;

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

void insert(int value){

	struct node *teamp=(struct node *)malloc(sizeof(struct node));
	teamp->value=value;
	teamp->left=NULL;
	teamp->right=NULL;

	if(root==NULL){
       root=teamp;
   
	}
	else{
		 struct node *teampnode=root,* parent;
		while(teampnode)
		{
			parent=teampnode;
 
			if(teampnode->value>value)
				{

					teampnode=teampnode->left;
					if(teampnode==NULL)
					   parent->left=teamp;

							}
					else{
                     teampnode=teampnode->right;
                     if(teampnode==NULL)
                     	parent->right =teamp;

					}

		}

	}

    	printf("-------------------------------------------------------------\n");

	inorder(root);

    	printf("\n---------------------------------------------------------------\n");
}



struct node *min(struct node *root ){
  
  struct node *teamp=root;
   while(teamp->left){

   	teamp=teamp->left;
   }

   return teamp;

}




struct node *delete(struct node *root,int key){
	if(root==NULL)
		return root;    

	if(root->value>key){   // move left

		root->left=delete(root->left,key);
	}
	else if(root->value<key)   // move right 
		root->right=delete(root->right,key);

	else{
           // one child 
		if(root->left==NULL){    // no left node 
			{
			struct node *teamp=root->right;
			free(root);
			return teamp;
		}

		if (root->right==NULL){
           struct node *teamp=root->left;
			free(root);  // no right node
			return teamp; 

		}

		// Two child  
		struct node * teamp=min(root->right);
		root->value=teamp->value;
		root->right=delete(root->right,teamp->value);
		}

		return root;
	}





}


void search(struct node *root,int iteam){

	if(root==NULL){
		printf("NOT  FOUND ");
		return ;

	}


	if(root->value<iteam){
		search(root->right,iteam);

	}
	else if(root->value<iteam){
		search(root->left,iteam);
	}
	else if(iteam==root->value){


		printf("found \n");
	}
	else{
		printf("not found\n");
	}

}







int height(struct node *root){


	if(root==NULL)
		return 0 ;
	else
		{
			int l_height=height(root->left);
			int r_height=height(root->right);

			if(l_height>r_height)
				return l_height+1;
			else
				return r_height+1;




		}
}




int bst(struct node *node ,int min , int max){

	if(node==NULL)
		return 1;

	if(node->value < min || node->value > max)
		return 0;
	else 
		return bst(node->left,min,node->value-1)&&bst(node->right,node->value+1,max);



}


int Bstornot(struct node* node){


	return bst(node,INT_MIN,INT_MAX);
}




int main(int argc, char const *argv[])
{
	
	int iteam;

	while(1){
		printf("\n 1. insert  \n 2. delete  \n 3. inorder  \n 4. search \n 5. height  \n 6. Bstornot \n 9. exit    \n ");
		int c;
		scanf("%d",&c);


switch(c){

	case 1 : 
	        printf("Enter iteam to insert \n");
	        scanf("%d",&iteam);
	        insert(iteam);
	        break;

	case 2 : 

	       printf("delete iteam from tree\n");
	       scanf("%d",&iteam);
	       delete(root,iteam);

	       break; 


	case 3:
	    printf("inorder sequence \n"); 
	    inorder(root);
        break;


    case 4:
          printf("search ....\n");
          scanf("%d",&iteam);
          search(root,iteam);
          break;


    case 5 :
          printf("height \n");
          int h=height(root);
          printf("%d\n",h );
          break;


    case 6:
          printf("Bstornot\n");
          if(Bstornot(root)){
          	printf("Yes\n");
          }
          else
          	printf("NOT\n");
          break;

    case 9: return 0;

        }
     
         }
  

return 0;

      }
