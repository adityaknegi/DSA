#include <stdio.h>
#include<limits.h>


int max1(int a,int b){
    
    return (a>b)?a:b;
}

int max(int a,int b,int c){
    
    return max1(max1(a,b),c);    
}

int max_sum_crossing(int a[],int low, int m, int high){
    int sum=0;
    int left_sum=INT_MIN; // MINIMUM VALUE FIXED
    int s;//starting postion
    for(int i=m ; i>=low ; i--){
        sum=sum+a[i];
        if(sum>left_sum){
            left_sum=sum;
            s=i; // starting point future use 
    }
        
    }
    
    int right_sum=INT_MIN; // MINIMUM VALUE FIXED 
    sum=0;
    int e;//starting postion
    for(int i=m+1;i<=high;i++){
        sum=sum+a[i];
        if(sum>right_sum){
            right_sum=sum;
            e=i; // end point future use
        }
    }
    
    return (left_sum + right_sum);
}


int  max_sub_arry(int a[],int low, int high){
    if(high==low){
        return a[low]; // when only one iteam left return that 
    }
    
    int m=(high+low)/2; //  divide arry into half till size is 1
    	   

    int left_sum=max_sub_arry(a,low,m); // left subarry 
    int right_sum=max_sub_arry(a,m+1,high); // right subarry
    int crossing_sum=max_sum_crossing(a,low,m,high); // crossin point sum left_sum+right_sum
	    

    return max(left_sum,right_sum,crossing_sum); 
}

int main() {
	//code
	
	int t;
	scanf("%d",&t);
	
	while(t--){
	    
	    int size;
	    scanf("%d",&size);
	    int a[size];
	    for(int i=0;i<size;i++){
	        scanf("%d",&a[i]);
	    }
	    printf("%d\n", max_sub_arry(a,0,size-1));
	    
 //    print_sum(a,n);
	}
	
	return 0;
}
