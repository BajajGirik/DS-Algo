class Solution {
    public int minOperations(int[] nums, int k) {
      int xorResult = 0;

      for (int i=0; i<nums.length; ++i) {
        xorResult ^= nums[i];
      }

      xorResult ^= k;

      int ans = 0;
      for (int i=0; i<32; ++i) {
        if ((xorResult & (1 << i)) > 0) {
          ++ans;
        }
      }

      return ans;
    }
}
