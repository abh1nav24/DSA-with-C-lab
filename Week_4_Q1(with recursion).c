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

void reverse()
{
    if (top == -1)
        return;

    printf("%c", pop());

    reverse();
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

        while (str[i] != '\0')
        {
            push(str[i]);
            i++;
        }

        reverse();

        printf("\n");
    }

    return 0;
}
//Core Recursion Logic
//void reverse()
//{
//    if (top == -1)
//        return;
//
//    printf("%c", pop());
//
//    reverse();
//}
