//Without Recursion

#include <stdio.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    int T;
    char str[MAX];

    scanf("%d", &T);

    while (T--)
    {
        scanf("%s", str);

        top = -1;

        int i = 0;

        // Push all characters
        while (str[i] != '\0')
        {
            push(str[i]);
            i++;
        }

        // Pop and print in reverse
        while (top != -1)
        {
            printf("%c", pop());
        }

        printf("\n");
    }

    return 0;
}
