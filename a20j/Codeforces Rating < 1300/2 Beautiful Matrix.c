#include <stdio.h>

int absolute(int x, int y)
{
    if (x > y)
        return (x - y);

    return (y - x);
}

int main()
{
    int a[5][5], result;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &a[i][j]);

            if (a[i][j] == 1)
                result = absolute(i, 2) + absolute(j, 2);
        }
    }

    printf("%d\n", result);
}