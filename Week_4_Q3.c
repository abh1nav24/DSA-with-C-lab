#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    while (T--) {
        char expression[500];
        fgets(expression, sizeof(expression), stdin);

        top = -1;

        char *token = strtok(expression, " \n");

        while (token != NULL) {

            // If token is a number
            if (isdigit(token[0]) ||
                (token[0] == '-' && isdigit(token[1]))) {

                push(atoi(token));
            }

            // If token is an operator
            else {
                int b = pop();
                int a = pop();
                int result;

                switch (token[0]) {
                    case '+':
                        result = a + b;
                        break;

                    case '-':
                        result = a - b;
                        break;

                    case '*':
                        result = a * b;
                        break;

                    case '/':
                        result = a / b;
                        break;
                }

                push(result);
            }

            token = strtok(NULL, " \n");
        }

        printf("%d\n", pop());
    }

    return 0;
}
