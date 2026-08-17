#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int n;
        scanf("%d", &n);

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int a, b;
        scanf("%d%d", &a, &b);

        int min = n;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == a)
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[j] == b)
                    {
                        int distance = abs(i - j);

                        if (distance < min)
                        {
                            min = distance;
                        }
                    }
                }
            }
        }

        printf("%d\n", min);
    }

    return 0;
}
