class Solution {
public:
    int minDistance(string word1, string word2, int a = -2, int b = -2) {
        static vector<vector<int>> cost(word1.size(), vector<int>(word2.size(), -1));
    
        if(a == -2 || b == -2) {
            a = word1.size() - 1;
            b = word2.size() - 1;
        }
        
        if(a == -1)
            return b+1;
        if(b == -1)
            return a+1;
    
        if(cost[a][b] != -1)
            return cost[a][b];
        
        int cc = 1;
        if(word1[a] == word2[b])
            cc = 0;
        
        cost[a][b] = min({minDistance(word1, word2, a-1, b) + 1, minDistance(word1, word2, a, b-1) + 1, minDistance(word1, word2, a-1, b-1) + cc});
        
        return cost[a][b];
    }
};