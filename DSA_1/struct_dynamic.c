#include <stdio.h>
#include <stdlib.h> // for dynamic memory alllocation 


struct employee
{
char  name;
int  slary;
};
int main()
{
	printf("number of employees\n");
	int number;
	scanf("%d",&number);

	struct employee *emp1=(struct employee*)malloc(number*sizeof(struct employee));
	int i=number;
	while(i--){
		printf("----ENTER employee name and space slary: \n");
		printf("\n ENTER NAME: ");
		scanf("%s",&emp1->name);
		printf("\n ENTER slary: ");
		scanf("%d",&emp1->slary);

	}
     printf("----------------NAME AND SLARY OF EMPLOYESS------------------\n");
	while(number--){
		printf("\n      name=%s ,slary=%d \n ",&emp1->name,emp1->slary);
	}

	return 0;
}