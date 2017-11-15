// Write a C program that takes transition table as input(matrix) and checks whether given string is accepted by the DFA that is represented by that transition table.

//that your dfa consist  
#include<stdio.h>


int n_inputs_symbloe;

 
int dfa[10][10];
char final_states_c[10], string[10];



int simulation(char b,int d)
{
     int j;
     for(j=0; j<n_inputs_symbloe; j++)
     if(b==final_states_c[j])
     return(dfa[d][j]);
     return -1;
}

int main()
{
     int states, final_states;
     int f[10];     //final states
     int i,j,s=0,final=0;

     //.....................STATES NUMBER............................
     printf("enter the number of states\n      ....................STATES NUMBER............................ \n");    
     scanf("%d",&states);


     //    ...................Aphabetes.............
     printf("NUMBER of syble dfa have  \n");  
     
     scanf("%d",&n_inputs_symbloe);
     
     printf("\nenter input symbols\t");

     for(i=0; i<n_inputs_symbloe; i++) 
     {
           printf("\n\n %d input\t", i+1);
           scanf("%s",&final_states_c[i]);
     }



     //................//FINAL STATES.................

     printf("\n\nENTER number of  FINAL STATES :: \t");         
     scanf("%d",&final_states);

     for(i=0;i<final_states;i++)                                
     {
          printf("\n\nFinal state %d : q",i+1);
          scanf("%d",&f[i]);
     }

     //  ......................................Transition table as input .......................


     printf("......................................Transition table as input .......................");

     printf("\n\ndefine transition rule as (initial state, input symbol ) = final state\n");

     for(i=0; i<n_inputs_symbloe; i++)
     {
          for(j=0; j<states; j++)
          {
               printf("\n(q%d , %c ) = q",j,final_states_c[i]);
               scanf("%d",&dfa[i][j]);
          }
     }

   while(1){
        
             i=0;
             printf("\n\n Input String.. ");
             scanf("%s",string);
   
             while(string[i]!='\0')
             if((s=simulation(string[i++],s))<0)
             break;
             for(i=0 ;i<final_states ;i++)
             if(f[i] ==s )
             final=1;
             if(final==1)
             printf("\n valid string"); 
             else
             printf("\n ................invalid string....................");

              printf("\n continue.?Yes =1 or No=0  \n(1/0) ");
              int c;
              scanf("%d",&c);
              if (c==1)
               continue;
             else
               break;
           



         }
}
