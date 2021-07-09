class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int len = s.size(), max = 0, i,j=0;		
			unordered_map<char, int> umap;

			for(i=0; i<len ;i++)
			{
				if(umap.find(s[i]) == umap.end())
				{
					umap[s[i]] = i;
				}
				else 
				{
					if(max < umap.size())
						max = umap.size();

					int temp = umap[s[i]];
					while(j != temp)
						umap.erase(s[j++]);
					j++;
					umap[s[i]] = i;
				}
			}
			
			if(max < umap.size())
				max = umap.size();

			return max;
		}
};
