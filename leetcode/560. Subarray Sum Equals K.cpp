class Solution
{
public:
	int subarraySum(vector<int> &nums, int k)
	{

		unordered_map<int, int> m;
		m[0] = 1;

		int sum = 0, total = 0;
		for (auto num : nums)
		{
			sum += num;

			if (m.find(sum - k) != m.end())
				total += m.find(sum - k)->second;

			if (m.find(sum) != m.end())
				++m[sum];
			else
				m[sum] = 1;
		}

		return total;
	}
};