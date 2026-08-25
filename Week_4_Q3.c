#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int Top = -1;

void push(int value)
{
    stack[++Top] = value;
}

int pop()
{
    return stack[Top--];
}

void evaluate(char exp[], int i)
{
    int a, b, r;

    // End of string
    if (exp[i] == '\0')
    {
        printf("Result %d\n", pop());
        return;
    }

    // Ignore spaces
    if (exp[i] == ' ')
    {
        evaluate(exp, i + 1);
        return;
    }

    // If digit
    if (isdigit(exp[i]))
    {
        push(exp[i] - '0');
        evaluate(exp, i + 1);
        return;
    }

    // Operator
    b = pop();
    a = pop();

    switch (exp[i])
    {
        case '+':
            r = a + b;
            break;

        case '-':
            r = a - b;
            break;

        case '*':
            r = a * b;
            break;

        case '/':
            r = a / b;
            break;
    }

    push(r);
    evaluate(exp, i + 1);
}

int main()
{
    int T;
    char exp[MAX];

    scanf("%d", &T);

    while (T--)
    {
        Top = -1;

        scanf(" %[^\n]", exp);

        evaluate(exp, 0);
    }

    return 0;
}
