class Solution
{
public:
	char getLeftBracket(char ch)
	{
		if (ch == ')')
			return '(';

		if (ch == '}')
			return '{';

		return '[';
	}

	bool isValid(string s)
	{
		int tos = -1;
		char stack[5000];
		for (char ch : s)
		{
			if (ch == ')' or ch == '}' or ch == ']')
			{
				if (tos < 0 or stack[tos] != getLeftBracket(ch))
					return false;

				--tos;
			}
			else
				stack[++tos] = ch;
		}

		if (tos != -1)
			return false;

		return true;
	}
};