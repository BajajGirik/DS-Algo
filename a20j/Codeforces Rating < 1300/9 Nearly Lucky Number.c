#include <stdio.h>

int main()
{
    char s[20];
    scanf("%s", s);

    int totalLucky = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '4' || s[i] == '7')
            totalLucky++;
    }

    int flag = 1;
    while (totalLucky != 0)
    {
        if (totalLucky % 10 != 4 && totalLucky % 10 != 7)
        {
            flag = 1;
            break;
        }

        flag = 0;
        totalLucky /= 10;
    }

    flag ? printf("NO\n") : printf("YES\n");
    return 0;
}