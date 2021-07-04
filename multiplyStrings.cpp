class Solution {
    public:
        string multiply(string num1, string num2) {
            string ans;
            int itr = 0;
            for(int i=num2.length()-1; i>=0; i--)
            {
                int where = itr++;
                int mul = num2[i] - '0', carry = 0;
                for(int j=num1.length()-1; j>=0; j--)
                {
                    int mul2 = num1[j] - '0';
                    if(where == ans.length())
                        ans.push_back('0');
                    int val = mul*mul2 + carry + (int)(ans[where] - '0');
                    carry = val/10;
                    ans[where++] = val%10 + '0';
                }
                // leftover carry
                if(carry != 0)
                    ans.push_back(carry + '0');
            }

            for (char c : ans) 
                if (c != '0') 
                {
                    reverse(ans.begin(), ans.end());
                    return ans;
                }

            return "0";
        }
};
