class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto it: nums) {
            
            if(m.find(it) != m.end()) {
                ++m[it];
            } else {
                
                m[it] = 1;
            }
        }
        
        for(auto it: m) {
            if(it.second > nums.size()/2) {
                return it.first;
            }
        }
        
        return -1;
    }
};