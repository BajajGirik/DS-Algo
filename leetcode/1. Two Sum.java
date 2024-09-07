import java.util.HashMap;

class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> set = new HashMap<>();
        int[] result = new int[2];

        for (int i=0; i<nums.length; ++i) {
          if (set.containsKey(target - nums[i])) {
            result[0] = set.get(target - nums[i]);
            result[1] = i;
            break;
          }
          set.put(nums[i], i);
        }

        return result;
    }
 }
