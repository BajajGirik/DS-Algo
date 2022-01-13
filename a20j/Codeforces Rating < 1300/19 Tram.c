#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int leave, enter, noOfPeoplePresent = 0, maxPeople = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &leave, &enter);

		if (maxPeople < noOfPeoplePresent)
			maxPeople = noOfPeoplePresent;

		noOfPeoplePresent += (enter - leave);
	}

	printf("%d\n", maxPeople);
	return 0;
}