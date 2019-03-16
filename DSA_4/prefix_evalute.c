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


void evaluate_pre_fix(char pre_fix[], int n){

	
	char c;
	int a,b; // a is top ,b  is below a 


	for (int i = 0;pre_fix[n-i]!='(' ; i++)
	{
		c=pre_fix[n-i];

		if(isdigit(c)){
			//char c = '5';
           //int x = c - '0';

			push(c - '0');
		}
		else if(c=='*'||c=='/'||c=='+'||c=='-'){
			a=pop();
			b=pop();
			if(b==-1){
				printf("wrong exprssion\n");
							break;}

			switch(c){


				case '*':
				        push(a*b);
				        break;
				case '/':
				        push(a/b);
				        break;

				case '+':
				        push(a+b);
				        break;

				case '-':
				        push(a-b);
				        break;

			}


		}
  
	}
		int result=pop();
		printf(" result :%d\n", result);

}

int main()
{

	char pre_fix[max];
	int i;

    printf("ENTER Pre_FIX EXPRESSION \n");
	for ( i = 0; i < max-1; ++i)
	{
		
		scanf("%c",&pre_fix[i]);
		if(pre_fix[i]==')')
			break;
	}
   	

   	evaluate_pre_fix(pre_fix,i-2);

	
	return 0;
}
