#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        char str[1000];

        scanf("%s", str);

        int n = 0;

        // Find length of string
        while (str[n] != '\0')
        {
            n++;
        }

        int max = 0;

        // Starting position
        for (int i = 0; i < n; i++)
        {
            // Ending position
            for (int j = i; j < n; j++)
            {
                int count = 0;
                int valid = 1;

                // Check substring from i to j
                for (int k = i; k <= j; k++)
                {
                    if (str[k] == '(')
                    {
                        count++;
                    }
                    else
                    {
                        count--;
                    }

                    // More closing brackets than opening
                    if (count < 0)
                    {
                        valid = 0;
                        break;
                    }
                }

                // Valid substring
                if (valid == 1 && count == 0)
                {
                    int length = j - i + 1;

                    if (length > max)
                    {
                        max = length;
                    }
                }
            }
        }

        printf("%d\n", max);
    }

    return 0;
}
