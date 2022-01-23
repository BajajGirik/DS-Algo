#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        char s[n + 1];
        scanf("%s", s);

        int count = 0;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                count++;
        }

        count % 3 == 0 ? printf("Uttu\n") : printf("JJ\n");
    }

    return 0;
}