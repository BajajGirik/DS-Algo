class Solution {
public:
    static bool cmp (vector<int> a, vector<int> b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        
        return a[1] < b[1];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int last_end = -1;
        
        for(auto it: intervals) {
            int start = it[0];
            int end = it[1];
            
            if(start > last_end) {
                vector<int> temp {start, end};
                res.push_back(temp);
            } else {
                res.back()[1] = max(last_end, end);
            }
            
            last_end = max(last_end, end);
        }
        
        return res;
    }
};