#include <stdio.h>
#include <ctype.h>

#define max 100 

int top=-1;
int stack[100];


void push(int iteam){
	if(top==max-1){
		printf("overflow\n");
		return ;

	}
	else
		stack[++top]=iteam;
	return ;
}

int pop(){
	if(top==-1){
		printf("stack is Empty \n");
		return -1;
	}
	else{
		printf("pop  %d\n", stack[top] );
	    return stack[top--];
	}
}



void evaluate_post_fix(char post_fix[]){
	
	char c;
	int a,b; // a is top ,b  is below a 


	for (int i = 0;post_fix[i]!=')' ; i++)
	{
		c=post_fix[i];

		if(isdigit(c)){
			//char c = '5';
           //int x = c - '0';

			push(c - '0');
		}
		else if(c=='*'||c=='/'||c=='+'||c=='-'){
			a=pop();
			b=pop();

			switch(c){


				case '*':
				        push(b*a);
				        break;
				case '/':
				        push(b/a);
				        break;

				case '+':
				        push(b+a);
				        break;

				case '-':
				        push(b-a);
				        break;

			}


		}
  
	}

		int result=pop();
		printf(" result :%d\n", result);


}


int main()
{

	char post_fix[max];

    printf("ENTER PSOT_FIX EXPRESSION \n");
	for (int i = 0; i < max-1; ++i)
	{
		
		scanf("%c",&post_fix[i]);
		if(post_fix[i]==')')
			break;
	}
   	

   	evaluate_post_fix(post_fix);

	
	return 0;
}
