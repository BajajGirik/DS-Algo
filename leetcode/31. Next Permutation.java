class Solution {
    private void reverse(int[] nums, int start) {
      int end = nums.length-1;
      while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        ++start;
        --end;
      }
    }
    public void nextPermutation(int[] nums) {
      int index = -1;

      for (int i=nums.length-1; i>0; --i) {
        if (nums[i-1] < nums[i]) {
          index = i-1;
          break;
        }
      }

      if (index == -1) {
        reverse(nums, 0);
        return;
      }

      for (int i=nums.length-1; i>index; --i) {
        if (nums[i] > nums[index]) {
          int temp = nums[i];
          nums[i] = nums[index];
          nums[index] = temp;
          break;
        }
      }

      reverse(nums, index+1);
    }
}
