import java.util.*;

class Solution {
    public void nextPermutation(int[] nums) {
      int index = -1;

      for (int i=nums.length-1; i>0; --i) {
        if (nums[i-1] < nums[i]) {
          index = i-1;
          break;
        }
      }

      Arrays.sort(nums, index + 1, nums.length);

      if (index == -1) {
        return;
      }

      for (int i=index+1; i<nums.length; ++i) {
        if (nums[i] > nums[index]) {
          int temp = nums[i];
          nums[i] = nums[index];
          nums[index] = temp;
          break;
        }
      }
    }
}
