class Solution
{
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
	{
		unordered_set<int> s;
		for (auto num1 : nums1)
			s.insert(num1);

		vector<int> res;
		for (auto num2 : nums2)
		{
			if (s.find(num2) != s.end())
			{
				res.push_back(num2);
				s.erase(num2);
			}
		}

		return res;
	}
};