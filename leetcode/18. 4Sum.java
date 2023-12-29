import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        HashSet<String> alreadyAddedPairsSet = new HashSet<>();
        List<List<Integer>> results = new ArrayList<>();

        for (int i = 0; i < nums.length - 3; ++i) {
            for (int l1 = i + 1; l1 < nums.length - 2; ++l1) {
                int j = nums.length - 1;
                for (int l2 = l1 + 1; l2 < j;) {
                    long currSum = (long)nums[i] + nums[l1] + nums[l2] + nums[j];

                    String currSumKey = nums[i] + "," +
                            nums[l1] + "," +
                            nums[l2] + "," +
                            nums[j];

                    if (currSum == target) {
                        if (!alreadyAddedPairsSet.contains(currSumKey)) {
                            ArrayList<Integer> list = new ArrayList<>(
                                    List.of(nums[i], nums[l1], nums[l2], nums[j]));
                            results.add(list);
                            alreadyAddedPairsSet.add(currSumKey);
                        }
                        l2++;
                        j--;
                    } else if (currSum > target) {
                        j--;
                    } else {
                        l2++;
                    }
                }
            }
        }

        return results;
    }
}
