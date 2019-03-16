//min height of tree floor log2(N)+1.


#include <stdio.h>
#include <math.h>

int min(int value){
int i=0;
while(1){
 value = value - 2^i;
 
printf("value =%d- 2^%d \n",value,i);
 
if(value<=0)
   return i--;
i++;
   }

return i--;


}



int main(){

int n;
scanf("%d",&n);

int value=min(n);

printf("%d",value);

}
