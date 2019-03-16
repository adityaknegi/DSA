#include <stdio.h>
#include <stdlib.h>

// increasing order array 

int main(){
	int size;
	printf("ENTER NUMBER OF ELEMENTES \n");
	scanf("%d",&size);
	int *a ; // array

	a = (int*) malloc(size*sizeof(int)); // arry of size n 
	printf("ENTER array:  \n");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d",a+i); 
	}
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if(*(a+j)>*(a+j+1)){
				int teamp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=teamp;
			}
		}
	}

	for (int i = 0; i < size; ++i)
	{
		printf("%d >",*(a+i));
	}


}
