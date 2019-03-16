#include<stdio.h>
int long_mon(int a[], int n){
        if(n==1)
            return 1;
        int i=0, j=1; //
        int val[n];  // value smaller then it +1  counting store 
        while(i!=n){
        val[i++]=1;    
        }
        
        i=0;
        int max=1 ; // store max value 
        int k=n-1;   //   i can only move till n-1 index and when it reach i-1 index (a[n-2]) index j at nth index(a[n-1]) so exit 

        while(k--){
            while(i!=j){  // i always smaller then j , i used for check set of  element val[i]+1 are less then j index element  or not 
                        if(a[i]<=a[j]){
                            int value=val[i]+1;  // to store how many small value then a[i] has val[i]+1 value for val[j]
                            if(value>val[j]) {    // if val[j] less then new set of number then replace 
                                val[j]=value;
                                     if(value>max)    
                                         max=value;  // store max value 
                              }
                            // printf("a[%d] <=a[%d] a[%d]=%d \n",i,j,j,a[j] ); // for check working or not 
                             i++; // move to next index 
                          
                        }
                        else
                            i++; // till i==j check it 
                    }
                        i=0;  
                        j++;
              
            
        }
         // returns max
        return max;
    }

/* Driver program to test above function */
int main()
{
     int n;
    printf("Enter number of  elements N:  ");
    scanf("%d",&n);
    if(n==0){
        printf("EMPTY SET \n");
        return 0;
    }
    int arr[n];
  
    for(int i=0;i<n;i++){
    printf("ENTER A[%d] = ",i);
          scanf("%d",&arr[i]);
   }
    printf("Length of lis is\n %d \n", long_mon( arr, n ) );

    return 0;
}
