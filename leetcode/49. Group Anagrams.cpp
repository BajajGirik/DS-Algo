class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		unordered_map<string, vector<string>> m;

		int i = 0;
		for (auto str : strs)
		{
			sort(str.begin(), str.end());
			auto it = m.find(str);

			if (it != m.end())
				it->second.push_back(strs[i]);
			else
			{
				vector<string> v;
				v.push_back(strs[i]);
				m.insert(make_pair(str, v));
			}

			++i;
		}

		vector<vector<string>> res;
		for (auto it : m)
			res.push_back(it.second);

		return res;
	}
};