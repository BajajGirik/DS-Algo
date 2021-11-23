#include<iostream>
#include<unordered_set>

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		int n, k, temp;
		std::cin >> n >> k;

		std::unordered_set<int> s;
		bool flag = false;
		for(int i=0;i<n;i++)
		{
			std::cin >> temp;
			if (s.find(k-temp) != s.end()) 	
				flag = true;
			s.insert(temp);
		}
		if(flag)
			std::cout << "Yes\n";
		else
			std::cout << "No\n";
	}
	
	return 0;
}
