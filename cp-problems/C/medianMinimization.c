#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll cmpfunc(const void *a, const void *b)
{
    return (*(ll *)a - *(ll *)b);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        ll a[n];
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        qsort(a, n, sizeof(a[0]), cmpfunc);
        printf("%lld\n", a[(n - 1) / 2] - a[(n - 3) / 2]);
    }
    return 0;
}