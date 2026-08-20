#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        char str[1000];
        scanf("%s", str);

        int length = 0;

        // Find length
        while (str[length] != '\0')
        {
            length++;
        }

        int changed = 1;

        while (changed == 1)
        {
            changed = 0;

            for (int i = 0; i < length - 1; i++)
            {
                if ((str[i] == '(' && str[i + 1] == ')') ||
                    (str[i] == '{' && str[i + 1] == '}') ||
                    (str[i] == '[' && str[i + 1] == ']'))
                {
                    // Remove these two brackets
                    for (int j = i; j < length - 2; j++)
                    {
                        str[j] = str[j + 2];
                    }

                    length = length - 2;
                    str[length] = '\0';

                    changed = 1;
                    break;
                }
            }
        }

        if (length == 0)
            printf("Balanced\n");
        else
            printf("Unbalanced\n");
    }

    return 0;
}
