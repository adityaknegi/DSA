#include<stdio.h>
#include <time.h> // for camparsion between base 2 an base 3 function 
// base 2 function (1,0)


// base 2 function (1,0)
int base2power(int x , int n){
       int z=1;
       if(n==0)
            return 1;

while(n!=1){

// 10111  X^1*X^2*X^4*X^16=X^23  X^8 MISSING BECAUSE 0 DIGIT   
     if(n&1)       //n is odd then n&1=0 else 1   
      z=z*x;       // X^1 ,x^2,x^4,x^6
      x=x*x;       //X^2 X^4 X^8 X^16
      n=n>>1;      //>> RIGHT SHIFT

		   }
     if(n==1)
      z=z*x;       // if end digit is 1 
	    return z;
}


// base 3 function (1,0,2)
//for 23 
// 0,1,2,10,11,12,20,21,22,100,101,102,110,111,112,121,122,200
int base3power(int x , int n){
  int z=1;
       if(n==0)
            return 1;

while(n>0){                                            // 23%3-->1  means x^n*1
     if(n%3==1)       //n is odd then n&1=0 else 1   
     { z=z*x;       // X^1 ,x^3,x^9,x^27
       
     }     
    else if (n%3==2)
        { z=z*x;       // 23%3-->2  means x^n*2 if // 23%3-->0  means x^n*0
          z=z*x;}
       x=x*x*x;       //X^3 X^9 X^27 X^81 ...
      n=n/3;      
		   }	  
		     return z;}

int main(){
      int n;
      int p=1, x;
      printf("x^n Enter X AND N  \n");
      printf("ENTER X:");

      scanf("%d",&x);
      printf("ENTER n:");
      scanf("%d",&n);
      double  msec2 = 0,msec1=0; /* 10ms */

//for(int i=1;i<n;i++)
//    printf("%d&2  %d  \n ",i,i&1);
//----------------------------------for base 2 system ---------------------------------------

      printf("  \n\n\n-----------------------------------for base 2 system ---------------------------------------\n\n\n\n\n  >> "); 

      clock_t before = clock();
  for(int i=0;i<n;i++)
            printf("  %d^%d=%d  > ",x,i,base2power(x,i)); 
      clock_t difference1 = clock() - before;
      msec1 = difference1 * 1000000 / CLOCKS_PER_SEC; //10^6
      long long millsec=msec1*1000;
      printf("Time taken %lf milliseconds  %llu microseconds \n",msec1 , millsec%1000);
  
      
//----------------------------------for base 3 system ---------------------------------------

     
     printf("  \n\n\n-----------------------------------for base 3 system ---------------------------------------\n\n\n  >> "); 

      before = clock();
  for(int i=0;i<n;i++)
             printf("  %d^%d=%d  > ",x,i,base3power(x,i)); 
    clock_t difference2 = clock() - before;
    msec2 = difference2*1000000  / CLOCKS_PER_SEC; // 10^6
    
    millsec=msec2*1000;
    printf("Time taken %lf milliseconds %llu microseconds \n",msec2, millsec%1000);
    printf("\n\n\n\n");




	if(difference1<difference2)
	    printf("base 2 is faster then base 3 system \n ");
	else if (difference1==difference2)
	    printf("both have equality effiecient \n");
	else
	    printf("base 3 is faster then base 2 system  \n ");

return 0;

}









