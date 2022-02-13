#include <iostream>
#include <unordered_map>

int main()
{
	int n;
	std::cin >> n;

	int a[n], b[n];
	std::unordered_map<int, int> m;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i] >> b[i];
		if (m.find(a[i]) != m.end())
			++m[b[i]];
		else
			m[b[i]] = 1;
	}

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (m.find(a[i]) == m.end() or (m[a[i]] == 1 && a[i] == b[i]))
			++count;
	}

	std::cout << count << "\n";
	return 0;
}