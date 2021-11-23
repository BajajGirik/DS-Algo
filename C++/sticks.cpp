#include<iostream>
#include<map>
#include<cmath>
#define maximum(a,b) a>b? a:b

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		map<int, int> mp;
		int temp;
		for(int i=0; i<n; i++)
		{
			cin >> temp;
			mp[temp] += 1;	
		}

		int count = 2;
		int prod = 1;
		for(auto itr=mp.rbegin(); itr!=mp.rend() && count ; itr++)
		{
			if(itr->second >= 2) {
				int temp = itr->second/2;
				int old_count = count;
				count = maximum(0,count-temp);
				prod *= pow(itr->first ,(old_count-count));
			}
			
		}
		if (count != 0)
			prod = -1;
		cout << prod << endl;
	}
	return 0;
}
