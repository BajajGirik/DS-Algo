class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int maxLength = 1; 
      vector<int> length(nums.size(), 1);
        
       for(int i = 1; i < nums.size(); ++i) 
           for(int j = 0; j < i; ++j) {
               if(nums[i] > nums[j]) {
                   length[i] = max(length[i], length[j] + 1);
                   maxLength = max(maxLength, length[i]);
               }
           }
        
        return maxLength;
    }
};