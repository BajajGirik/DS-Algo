class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int left = 0, right = a.size() - 1;
        vector<int> v(2,-1);
        
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if(a[mid] == target) {
                v[0] = mid;
                right = mid - 1;
            } else if(a[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        if(v[0] == -1) {
            return v;
        }
        
        left = v[0];
        right = a.size() - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if(a[mid] == target) {
                v[1] = mid;
                left = mid + 1;
            } else if(a[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return v;
    }
};