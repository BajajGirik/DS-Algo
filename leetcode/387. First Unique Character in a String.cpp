class Solution
{
public:
	int firstUniqChar(string s)
	{

		unordered_map<char, int> m;

		for (auto ch : s)
		{
			if (m.find(ch) == m.end())
				m.insert(make_pair(ch, 1));
			else
				++m[ch];
		}

		int i = 0;
		for (auto ch : s)
		{
			if (m[ch] == 1)
				return i;

			++i;
		}

		return -1;
	}
};