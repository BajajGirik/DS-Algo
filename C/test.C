#include<stdio.h>

int main() {
	int m=20, n=9;
	int x = 0, y = 4;
	while(m--) {
		printf("%d   %d\n",x, y);
		x = (x+7)%(n-1);
		y = (y+11)%n;
	}
	return 0;
}
