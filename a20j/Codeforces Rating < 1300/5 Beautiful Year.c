#include <stdio.h>
#include <stdbool.h>

bool distinct(int n)
{
    int a[10] = {0};
    while (n != 0)
    {
        if (a[n % 10]++)
            return false;

        n /= 10;
    }

    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    n++;

    while (!distinct(n++));

    printf("%d\n", n-1);
    return 0;
}