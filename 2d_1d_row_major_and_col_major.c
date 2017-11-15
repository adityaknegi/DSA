#include <stdio.h>


 int main(){
	int r,c,j=0; // row , columns 
	scanf("%d%d",&r,&c);
	// for row major 2d array in 1d array
	printf("-------------------Row major 2D array in 1D array------------------\n");

	int row_major[r*c],col_major[r*c];

    for (int i = 0; i < r*c; i++)
    {

    	if(i%c==0){
    		printf("ENTER %d ROW\n",j);
    	}
    	scanf("%d",&row_major[i]);
    	col_major[(i%c)*r+j]=row_major[i];
    	printf("(i''c)*r+j=%d \n ",(i%c)*r+j );
    	if((i+1)%c==0)
    		j++;
    }
    printf("\n--------------row-major-------------------\n\n");
    for (int i = 0; i < r*c; ++i)
    {
    	printf("%d ,",row_major[i] );
    }

     printf("\n--------------col-major-------------------\n\n");
    for (int i = 0; i < r*c; ++i)
    {
    	printf("%d ,",col_major[i] );
    }


    // Now search in one of them 
    int s_r,s_c,choice;
    while(1){
    	printf("ENTER ROW AND columns\n");


    	printf("\n 1 for --------------row-major-------------------\n\n");

    	printf("\n 2 for --------------col-major-------------------\n\n");

    	printf("\n 3 for -------------- EXIT -------------------\n\n");
    	scanf("%d",&choice);

        
            switch(choice){
            	case 1:  
            	      printf("ENTER ROW AND columns\n");
    	              scanf("%d%d",&s_r,&s_c);
                      printf("M[%d][%d]=%d \n ",s_r-1,s_c-1,row_major[(s_r-1)*r+s_c-1]);
                      break;
            
                case 2: 
            	      printf("ENTER ROW AND columns\n");
    	              scanf("%d%d",&s_r,&s_c);
                      printf("M[%d][%d]=%d \n ",s_r-1,s_c-1,col_major[s_r-1 +(s_c-1)*c]);
                      break;
                case 3: return 0;

                default: break;

    }
}
}