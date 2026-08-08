#include <stdio.h>
#include <string.h>

#define MAX 1000

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        char str[MAX];
        char stack[MAX];
        int top = -1;
        int balanced = 1;

        scanf("%s", str);

        for (int i = 0; i < strlen(str); i++)
        {
            // Opening brackets
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                top++;
                stack[top] = str[i];
            }

            // Closing brackets
            else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if (top == -1)
                {
                    balanced = 0;
                    break;
                }

                if ((str[i] == ')' && stack[top] == '(') ||
                    (str[i] == '}' && stack[top] == '{') ||
                    (str[i] == ']' && stack[top] == '['))
                {
                    top--;
                }
                else
                {
                    balanced = 0;
                    break;
                }
            }
        }

        // If brackets are still present
        if (top != -1)
        {
            balanced = 0;
        }

        if (balanced == 1)
        {
            printf("Balanced\n");
        }
        else
        {
            printf("Unbalanced\n");
        }
    }

    return 0;
}
