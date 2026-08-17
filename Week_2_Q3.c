#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Save top-left element
    int temp = a[0][0];

    // Move first column up
    for (int i = 0; i < n - 1; i++)
    {
        a[i][0] = a[i + 1][0];
    }

    // Move bottom row left
    for (int j = 0; j < n - 1; j++)
    {
        a[n - 1][j] = a[n - 1][j + 1];
    }

    // Move last column down
    for (int i = n - 1; i > 0; i--)
    {
        a[i][n - 1] = a[i - 1][n - 1];
    }

    // Move top row right
    for (int j = n - 1; j > 1; j--)
    {
        a[0][j] = a[0][j - 1];
    }

    a[0][1] = temp;

    // Print matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
