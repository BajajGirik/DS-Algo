#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x = 0, y = 0, z = 0;

    while (n--)
    {
        int xtemp, ytemp, ztemp;
        scanf("%d %d %d", &xtemp, &ytemp, &ztemp);

        x += xtemp;
        y += ytemp;
        z += ztemp;
    }

    x || y || z ? printf("NO\n") : printf("YES\n");
}