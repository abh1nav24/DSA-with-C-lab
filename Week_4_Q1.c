#include <stdio.h>
#include <string.h>

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

        // Push characters into stack
        for (int i = 0; str[i] != '\0'; i++)
        {
            push(str[i]);
        }

        // Pop characters to reverse the string
        while (top != -1)
        {
            printf("%c", pop());
        }

        printf("\n");
    }

    return 0;
}
