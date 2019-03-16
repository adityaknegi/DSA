#include<stdio.h>
#include<stdlib.h> 
// An expression tree node
struct et
{
    char value;
    struct  et* left, *right;
};
 
// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}
 
// Utility function to do inorder traversal
void inorder(struct et *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}
 
// A utility function to create a new node
struct  et* newNode(int v)
{
    struct et *temp = (struct et *)malloc(sizeof(struct et));
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
 
// Returns root of constructed tree for given
// postfix expression
struct et* constructTree(char postfix[])
{
    stack<et *> st;
    struct et *t, *t1, *t2;
 
    // Traverse through every character of
    // input expression
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);
 
            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
 
            //  make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;
}
 

int main()
{
    char postfix[] = "ab+ef*g*-";
    struct  et* r = constructTree(postfix);
    printf("infix expression is \n");
    inorder(r);
    return 0;
