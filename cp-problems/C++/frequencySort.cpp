#include<iostream>
#include<vector>
#include<map>
#include<utility>

using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b)
{
	return a.second > b.second;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		map<int,int> m;
		vector<pair<int,int>> v;
		int i, n;
		cin >> n;
		for(i=0;i<n;i++)
		{
			int temp;
			cin >> temp;
			m[temp] += 1;
		}

		for (auto& it : m) 
			v.push_back(it);

		sort(v.begin(), v.end(), compare);
		for(auto& it : v)
		{
			while(it.second--)
				cout<<it.first;
		}
		cout<<"\n";
	}
	return 0;
}
