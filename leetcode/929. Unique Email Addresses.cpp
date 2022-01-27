class Solution
{
public:
	int numUniqueEmails(vector<string> &emails)
	{

		unordered_set<string> s;
		for (auto email : emails)
		{
			string formattedEmail = "";
			bool flag = false;
			int i = 0;
			for (auto ch : email)
			{
				++i;

				if (ch == '@')
					break;

				if (flag)
					continue;

				if (ch == '.')
					continue;

				if (ch == '+')
				{
					flag = true;
					continue;
				}

				formattedEmail += ch;
			}

			--i;
			for (; i < email.size(); ++i)
				formattedEmail += email[i];

			s.insert(formattedEmail);
		}

		return s.size();
	}
};