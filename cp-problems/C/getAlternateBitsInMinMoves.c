#include <stdio.h>
#define min(x, y) x < y ? x : y

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, totalMoves1 = 0, totalMoves2 = 0, flag1 = 0, flag2 = 0;
        scanf("%d", &n);

        char s[n + 1], bits[2] = {'0', '1'};
        scanf("%s", s);

        for (int i = 0; i < n; i++)
        {
            if (s[i] != bits[i % 2])
                flag1 = 1;

            else if (s[i] == bits[i % 2] && flag1 == 1)
            {
                totalMoves1++;
                flag1 = 0;
            }

            if (s[i] != bits[(i + 1) % 2])
                flag2 = 1;

            else if (s[i] == bits[(i + 1) % 2] && flag2 == 1)
            {
                totalMoves2++;
                flag2 = 0;
            }
        }

        totalMoves1 += flag1;
        totalMoves2 += flag2;

        int totalMoves = min(totalMoves1, totalMoves2);

        printf("Total Moves 1 => %d\n", totalMoves1);
        printf("Total Moves 2 => %d\n", totalMoves2);
        printf("Total Moves => %d\n", totalMoves);

        if (totalMoves % 2 == 0)
            printf("Uttu\n");
        else
            printf("JJ\n");
    }

    return 0;
}