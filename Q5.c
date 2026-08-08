#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    int a[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int maxOnes = 0;
    int row = -1;

    for (int i = 0; i < m; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                count++;
            }
        }

        if (count > maxOnes)
        {
            maxOnes = count;
            row = i;
        }
    }

    if (row == -1)
    {
        printf("Not Present");
    }
    else
    {
        printf("row - %d", row + 1);
    }

    return 0;
}
