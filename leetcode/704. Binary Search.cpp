class Solution {
public:
    int search(vector<int>& a, int target) {
        int start = 0, end = a.size() - 1;
        
        while(start <= end) {
            int mid = (start + end) / 2;
            if(a[mid] == target) {
                return mid;
            }
            
            if(a[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return -1;
    }
};

