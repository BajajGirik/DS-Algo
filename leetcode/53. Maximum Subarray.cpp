class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, curr = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            curr += nums[i];
            if(curr > max)
                max = curr;
            
            if (curr < 0)
                curr = 0;
        }
        
        return max;
    }
};