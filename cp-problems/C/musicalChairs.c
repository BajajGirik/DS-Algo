#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long int n, i, count = 0;
        scanf("%lld", &n);

        for (i = 1; i * i < n - 1; i++)
        {
            if ((n - 1) % i == 0)
                count += 2;
        }

        if (i * i == n - 1)
            count++;

        printf("%lld\n", count);
    }

    return 0;
}