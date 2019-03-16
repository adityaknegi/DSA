#include <stdio.h>
#include <ctype.h>
# include <string.h>

#define max 100 

int top=-1;
int stack[100];
char output_list[100];


// insert iteam 
void push(char iteam){
	if(top==max-1){
		printf("overflow\n");
		return ;
	}
	else
		stack[++top]=iteam;
	return ;
}

// check stack is empty or not 
int isEmpty(){
 return top==-1;
}

// remove item 
char pop(){

	if(!isEmpty()){
		    return stack[top--];
	}
    else
	    	return 'e';
}

// top elememt 
char peek(){
	if(top==-1)
		return  'e';
	else
		return stack[top];
}


// set precedence  of operator 

int pec(char c){
	
			switch(c){
				case '*':
				case '/':
				        return 3;

				case '+':
				case '-':
				        return 2 ;
				        
	    		case ')':
                       return 1;
                       return -1;
			}
}

void reverse(char array[100])  {
	int i,j;
	char temp[100];
	for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
		temp[j]=array[i];
	}
	temp[j]='\0';
	strcpy(array,temp);
	return ;
}

// convert infix to profix 

void infix_to_prefix(char pre_fix[]){

	
	char c;
	int j=0;

	for (int i = 0;pre_fix[i+2]!=0 ; i++)
	{
    	c=pre_fix[i];

		if(isdigit(c)){         // if operand  then add in output list  
			//char c = '5';
           //int x = c - '0';
			output_list[j++]=c;

		}

		else if(c=='(')  // 
			push(c);

		 else if(c==')')              // if ) input then remove till '(' is remove  
         while(1){
         	output_list[j]=pop();
         	if(output_list[j]=='('){
         		//j--;   we will overlap  value on ( 
         		break;
         	}
         	j++;
         
         }

		else if(c=='*'||c=='/'||c=='+'||c=='-'){
		

			int pse_c=pec(c);                // operator  precedence 
			printf("pres=%d\n",pse_c );      
			int pse_top=pec(peek());        // stack top operator precedence 
		   while(peek()!='e'&&pse_top>=pse_c) // if not operator in stack then peek()=='e' && operator in stack  less precedence then leave loop
		   	     {	
		   	     	output_list[j]=pop();
		   	     	printf("%c\n", output_list[j] );
		   	     	j++;
		   		    pse_top=pec(peek());
		   		    }
		          push(c);
		}
  


      
	}




	// if stack is not  empty then empty and add  it to  output_list end 
	while(peek()!='e'){
		output_list[j++]=pop();
	}
          	reverse(output_list);


printf("\n");
		for (int i = 0; i<j; ++i)
		{
			
		printf(" %c", output_list[i]);
        }
}

int main()
{

	char pre_fix[max];
	int i;

    printf("ENTER INF_FIX EXPRESSION \n");
	for ( i = 0; i < max-1; ++i)
	{
		
		scanf("%c",&pre_fix[i]);
		if(pre_fix[i]=='0')   // end with 0 
			break;
	}
	i--;

    printf("aa\n");
	reverse(pre_fix);


   	infix_to_prefix(pre_fix);

	
	return 0;
}
