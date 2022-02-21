#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	int r, c;
	scanf("%d %d\n", &r, &c);

	bool safeRows[r], safeColummns[c];
	memset(safeRows, true, r * sizeof(bool));
	memset(safeColummns, true, c * sizeof(bool));

	for (int i = 0; i < r; ++i)
		for (int j = 0; j <= c; ++j)
		{
			char c;
			scanf("%c", &c);
			if (c == 'S')
			{
				safeRows[i] = false;
				safeColummns[j] = false;
			}
		}

	int rows = 0;
	for (int i = 0; i < r; ++i)
		if (safeRows[i])
			++rows;

	int count = rows * c;
	for (int i = 0; i < c; ++i)
		if (safeColummns[i])
			count += r - rows;

	printf("%d\n", count);
	return 0;
}