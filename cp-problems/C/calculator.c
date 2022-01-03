#include<stdio.h>

int main()
{
	double a, b;
	char c;

	scanf("%lf\n",&a);
	scanf("%lf\n",&b);
	scanf("%c",&c);

	switch (c) {
		case '+':
			printf("%f\n", a + b);
			break;
		case '-':
			printf("%f\n", a-b);
			break;
		case '*':
			printf("%f\n", a*b);
			break;
		case '/':
			printf("%f\n", a/b);
			break;
	}
	return 0;
}
