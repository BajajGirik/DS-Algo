import java.util.Arrays;

class Solution {
    private int upperBinarySearch(int[] nums, int start, int end, int target) {
        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }

    private int lowerBinarySearch(int[] nums, int start, int end, int target) {
        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }


    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        int i=0;
        long result = 0;

        while (i < nums.length - 1) {
            int left = lowerBinarySearch(nums, i+1, nums.length, lower - nums[i]);
            int right = upperBinarySearch(nums, left, nums.length, upper - nums[i]);
            result += right - left;
            ++i;
        }

        return result;
    }
}

