class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> u;
		int i=0;
		vector <int> v(2);

		for(auto element : nums)
		{
			if(u.find(target-element) == u.end())
				u[element] = i;
			else
			{
				v[0] = u[target-element];
				v[1] = i;
				break;
			}
			i++;
		}
		
		return v;
    }
};
