#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int x, sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		sum += x;
	}

	cout << sum * (1.0) / n << "\n";
	return 0;
}