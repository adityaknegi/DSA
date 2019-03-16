
  #include <stdio.h>
  #include <string.h>

  #define BUFSIZE 100

  char operator[] = {'/', '*', '+', '-', '%', '$'};
  char stack[BUFSIZE][BUFSIZE];
  int top = -1;

  /* push input string into the stack */
  void push(char *substr) {
        char *temp;
        if (top >= BUFSIZE -1) {
                printf("Stack Overflow\n");
        } else {
                top++;
                strcpy(stack[top], substr);
        }
        return;
  }

  /* pop top element from the stack & append input string with top element */
  void pop(char *res) {
        if (top == -1) {
                printf("Stack Underflow\n");
                return;
        } else {
                strcpy(res, stack[top]);
                top--;
        }
        return;
  }

  int main() {
        char expr[BUFSIZE], buffer1[BUFSIZE];
        char str[BUFSIZE], buffer2[BUFSIZE], op[2];
        int i, j, len, flag = 0;
        printf("Enter your postfix expression:");
        fgets(expr, 100, stdin);
        expr[strlen(expr) - 1] = '\0';

        for (i = 0; expr[i] != '\0'; i++) {
                if (expr[i] == ' ')
                        continue;

                for (j = 0; j < 6; j++) {
                        if (expr[i] == operator[j]) {
                                flag = 1;
                                break;
                        }
                }

                if (flag) {

                        /*
                         * scanned char is an operator.  So, pop
                         * two elements from the stack and form a
                         * string composed on scanned char & two
                         * popped elements
                         */
                        pop(buffer1);
                        pop(buffer2);
                        op[0] = expr[i];
                        op[1] = '\0';
                        strcpy(str, op);
                        strcat(str, buffer2);
                        strcat(str, buffer1);
                        push(str);
                } else {

                        /* scanned character is digit, push it into ths stack */
                        op[0] = expr[i];
                        op[1] = '\0';
                        push(op);
                }
                flag = 0;
        }
        printf("Postfix to Prefix Conversion:\n");
        printf("Posfix: %s\n", expr);
        printf("Prefix: ");
        for (i = 0; i <= top; i++) {
                printf("%s",stack[i]);
        }
        printf("\n\n");
        return 0;
  }
