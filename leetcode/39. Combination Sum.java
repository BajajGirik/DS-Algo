import java.util.ArrayList;
import java.util.List;

class Solution {
  private List<List<Integer>> recurse(int[] arr, int target, int i) {
    List<List<Integer>> results = new ArrayList<>();

    if (target == 0) {
      results.add(new ArrayList<Integer>());
      return results;
    }

    if (target < 0 || i >= arr.length) {
      return results;
    }

    results = recurse(arr, target, i+1);
    List<List<Integer>> combinationsIfCurrentIncluded = recurse(arr, target - arr[i], i);

    for (List<Integer> combination: combinationsIfCurrentIncluded) {
      combination.add(arr[i]);
      results.add(combination);
    }

    return results;
  }

  public List<List<Integer>> combinationSum(int[] candidates, int target) {
    return recurse(candidates, target, 0);
  }
}
