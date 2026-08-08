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

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int freq[1001] = {0};

        // Count frequency
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }

        int found = 0;

        // Find odd occurrence
        for (int i = 0; i < n; i++)
        {
            if (freq[arr[i]] % 2 != 0)
            {
                printf("%d\n", arr[i]);
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            printf("No such element present\n");
        }
    }

    return 0;
}
