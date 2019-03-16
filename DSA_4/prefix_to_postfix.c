*/

Scan the Postfix Expression from Left To Right.
If the character is an Operand, then Push it on to the Stack.
If the character is an Operator, then Pop Operand 1 and Operand 2 and concatenate them and Push the result on the Stack.
Repeat the above steps until the Postfix Expression is scanned completely.
To get the Prefix Expression, Pop the remaining elements of the Stack.
*/

#include<stdio.h>
#include <string.h>
#include <ctype.h>


char opnds[50][80],oprs[50];
int  topr=-1,topd=-1;

void  pushd(char *opnd)
{
    strcpy(opnds[++topd],opnd);
}
char *popd()
{
    return(opnds[topd--]);
}
 
void pushr(char opr)
{
    oprs[++topr]=opr;
}
char popr()
{
    return(oprs[topr--]);
}
int empty(int t)
{
    if( t == 0) return(1);
    return(0);
}
 
int main()
{
    char prfx[50],ch,str[50],opnd1[50],opnd2[50],opr[2];
    int i=0,k=0,opndcnt=0;
 
    scanf("%s",prfx);

    while( (ch=prfx[i++]) != '\0')
    {
        if(isalnum(ch))
        {
            str[0]=ch; str[1]='\0';
            pushd(str); opndcnt++;
            if(opndcnt >= 2)
            {
                strcpy(opnd2,popd());
                strcpy(opnd1,popd());
                strcpy(str,opnd1);
                strcat(str,opnd2);
                ch=popr();
                opr[0]=ch;opr[1]='\0';
                strcat(str,opr);
                pushd(str);
                opndcnt-=1;
            }
        }
        else
        {
            pushr(ch);
            if(opndcnt==1)opndcnt=0;  /* operator followed by single operand*/
        }
    }
    if(!empty(topd))
    {
        strcpy(opnd2,popd());
        strcpy(opnd1,popd());
        strcpy(str,opnd1);
        strcat(str,opnd2);
        ch=popr();
        opr[0]=ch;opr[1]='\0';
        strcat(str,opr);
        pushd(str);
    }
    printf(" Postfix Expression: ");
    puts(opnds[topd]);
}

