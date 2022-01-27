class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> m;

		int i = 0;
		vector<int> v(2);

		for (auto x : nums)
		{
			auto it = m.find(target - x);
			if (it != m.end())
				return {it->second, i};

			m.insert(make_pair(x, i));
			++i;
		}

		return {-1, -1};
	}
};