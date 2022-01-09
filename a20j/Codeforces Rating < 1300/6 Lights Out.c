#include <stdio.h>

void toggle(int a[3][3], int i, int j)
{
    a[i][j] = (a[i][j] + 1) % 2;

    j <= 1 && (a[i][j + 1] = (a[i][j + 1] + 1) % 2);
    j >= 1 && (a[i][j - 1] = (a[i][j - 1] + 1) % 2);

    i <= 1 && (a[i + 1][j] = (a[i + 1][j] + 1) % 2);
    i >= 1 && (a[i - 1][j] = (a[i - 1][j] + 1) % 2);
}

int main()
{
    int n, a[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &n);
            if (n % 2 != 0)
                toggle(a, i, j);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d", a[i][j]);

        printf("\n");
    }
    return 0;
}