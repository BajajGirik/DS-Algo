#include <stdio.h>

int absolute(int x, int y)
{
    if (x > y)
        return (x - y);

    return (y - x);
}

int main()
{
    int x, result;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &x);

            if (x == 1)
                result = absolute(i, 2) + absolute(j, 2);
        }
    }

    printf("%d\n", result);
}