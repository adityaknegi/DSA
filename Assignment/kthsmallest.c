//	q). Given a randomly ordered array of ' n' elements. Determine the kth smallest element in the set.

// used Quicksort 
#include<stdio.h>
 
# define INT_MAX -1

int partition(int arr[], int l, int r);
 
// This function returns k'th smallest element in arr[l..r] 
//  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);
 
        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos-1, k);
 
        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
 
 
}
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
 

int main()
{

    int n,k;
    printf("Enter number of  elements N:  ");
    scanf("%d",&n);
    int arr[n];
    printf("kth smallest elemen is:  ");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
    printf("ENTER A[%d] = ",i);
          scanf("%d",&arr[i]);
  
}

    if(k<=n)
    printf("K'th smallest element is %d \n " , kthSmallest(arr, 0,n-1, k));
    else
        printf("Number of elements are less then  K   N<K \n " );
    return 0;
}



