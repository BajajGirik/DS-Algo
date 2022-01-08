#include <stdio.h>

int main()
{
    char s[201];
    scanf("%s", s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '.')
            printf("0");

        else if (s[i] == '-' && s[i + 1] == '.')
        {
            printf("1");
            i++;
        }
        else
        {
            printf("2");
            i++;
        }
    }

    printf("\n");
}