#include <stdio.h>

int main()
{
    int n, result = 0;
    scanf("%d", &n);

    char s[n + 1];
    scanf("%s", s);

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            result++;
    }

    printf("%d\n", result);

    return 0;
}