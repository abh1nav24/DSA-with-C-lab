#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        int n;
        scanf("%d", &n);

        int arr[n];

        // Input array
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int k;
        scanf("%d", &k);

        // Left rotate k times
        for (int r = 0; r < k; r++)
        {
            int temp = arr[0];

            for (int i = 0; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            arr[n - 1] = temp;
        }

        // Print rotated array
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }

    return 0;
}
