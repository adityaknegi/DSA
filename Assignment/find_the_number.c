/*question:
An array  A contains (n-1) unique intergers in the range [0,n-1], that is there is one number from this range that is not in A. Design an O(n) time algorithm for finding that number. You are allowed to use only O(1) additional space besides the array A itself.
*/



//Sum up the numbers from from 0 to n-1 and then find the sum of the array and the missing number is sum - sum of array

#include<stdio.h>


int main(){

    int n;
    printf("Enter number of  elements N-1:  ");
    scanf("%d",&n);
    int arr[n];
   int sum=0;

    for(int i=0;i<n;i++){
    printf("ENTER A[%d] = ",i);
          scanf("%d",&arr[i]);
          sum=sum+arr[i];   
}	
    for(int i=0;i<n+1;i++){
        sum=sum-i; 
}
sum=sum*-1;
printf("Missing number is %d \n ",sum);
    return 0;

}
