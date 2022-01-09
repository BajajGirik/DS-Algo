#include <stdio.h>

int main()
{
    char s[101];
    scanf("%s", s);

    int l = 0, u = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            l++;
        else
            u++;
    }

    int ascii;
    char letterCase[2];

    if (l >= u)
    {
        ascii = 32;
        letterCase[0] = 'A';
        letterCase[1] = 'Z';
    }
    else
    {
        ascii = -32;
        letterCase[0] = 'a';
        letterCase[1] = 'z';
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= letterCase[0] && s[i] <= letterCase[1])
            s[i] += ascii;
    }

    printf("%s\n", s);

    return 0;
}