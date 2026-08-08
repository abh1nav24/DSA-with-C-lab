#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int n;
        scanf("%d", &n);

        int result = 0;
        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);

            result = result ^ x;

            if (x == 0)
            {
                zeroCount++;
            }
        }

        if (result != 0)
        {
            printf("%d\n", result);
        }
        else if (zeroCount % 2 == 1)
        {
            printf("0\n");
        }
        else
        {
            printf("No such element present\n");
        }
    }

    return 0;
}
