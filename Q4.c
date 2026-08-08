#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    // Input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int key;
    scanf("%d", &key);

    int i = 0;
    int j = n - 1;
    int found = 0;

    // Start from top-right corner
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == key)
        {
            found = 1;
            break;
        }
        else if (matrix[i][j] > key)
        {
            j--;       // Move left
        }
        else
        {
            i++;       // Move down
        }
    }

    if (found == 1)
        printf("Present");
    else
        printf("Not Present");

    return 0;
}
