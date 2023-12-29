import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);

        int closestSum = nums[0] + nums[1] + nums[2];
        boolean foundClosestSum = false;

        for (int start=0, end=nums.length - 1; start<=end; ) {
            int midIndex = (start+end)/2;
            int initialSum = nums[start] + nums[midIndex] + nums[end];

            for (int mid=midIndex; mid>start && mid<end; ) {
                int currSum = nums[start] + nums[mid] + nums[end];
                if (Math.abs(target - currSum) < Math.abs(target - closestSum)) {
                    closestSum = currSum;
                }

                if (currSum == target) {
                    foundClosestSum = true;
                    break;
                }

                if (currSum > target && initialSum >= currSum) {
                    mid--;
                } else if (currSum < target && initialSum <= currSum) {
                    mid++;
                } else {
                    break;
                }
            }

            if (foundClosestSum) {
                break;
            }

            if (initialSum > target) {
                end--;
            } else {
                start++;
            }
        }

        return closestSum;
    }
}
