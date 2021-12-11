#include<iostream>
#include<map>
#define ll long long int

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n,i,flag=0;
		cin >> n;
		map<ll, ll> mp;
		ll temp;
		for(i=0;i<2*n;i++)
		{	
			cin >> temp;
			mp[temp] += 1;
		}

		temp = (n/2 -1 + n%2);
		ll a[n];
		i=0;

		for(auto ele : mp) {
			if(i==temp && ele.second != 3)
			{
				flag = 1;
				break;
			}

			else if((i==n-1 && ele.second!=1) ||(i!=n-1 && i!=temp && ele.second != 2))
			{
				flag = 1;
				break;
			}

			a[i] = ele.first;
			i++;
		}

		if(flag == 0 && i==n)
		{
			for(i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout << endl;
		}else if(n==1 && mp.begin()->second == 2) {
			cout << mp.begin()->first << endl;
		}
		else 
			cout << -1 <<endl;

	}
	return 0;
}
