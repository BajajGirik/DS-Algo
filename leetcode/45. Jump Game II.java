import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    private ArrayList<Integer> memo;

    public int findMinJumpsNonMemoized(int[] nums, int i, int count) {
        int n = nums.length;

        if (i > n-1) {
            return -1;
        }

        if (i == n-1) {
            return count;
        }

        int maxForward = nums[i];

        if (maxForward > n - i - 1) {
            return count + 1;
        }

        int minCount = Integer.MAX_VALUE;

        for (int index = i+1; index <= i + maxForward && index < n; ++index) {
            int res = findMinJumpsNonMemoized(nums, index, count + 1);
            if (res == -1) {
                continue;
            }

            minCount = Math.min(minCount, res);
        }

        if (minCount == Integer.MAX_VALUE) {
            return -1;
        }

        return minCount;
    }

    public int findMinJumps(int[] nums, int i) {
        int memoizedVal = this.memo.get(i);
        if (memoizedVal != -1) {
            return memoizedVal;
        }

        int n = nums.length;

        if (i > n-1) {
            return -1;
        }

        if (i == n-1) {
            return 0;
        }

        int maxForward = nums[i];

        if (maxForward > n - i - 1) {
            return 1;
        }

        int minCount = Integer.MAX_VALUE;

        for (int index = i+1; index <= i + maxForward && index < n; ++index) {
            int res = findMinJumps(nums, index) + 1;
            if (res < 0) {
                continue;
            }

            minCount = Math.min(minCount, res);
        }

        this.memo.set(i, minCount);
        return minCount;
    }

    public int jump(int[] nums) {
        this.memo = new ArrayList<>();
        for (int i=0; i<nums.length; ++i) {
            this.memo.add(-1);
        }

        int result = findMinJumps(nums, 0);
        this.memo = null;
        return result;
    }
}
