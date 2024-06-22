import java.util.ArrayList;
import java.util.List;

class Solution {
  private List<Integer> clone(List<Integer> list) {
    ArrayList<Integer> clonedList = new ArrayList<>();
    for (int item: list) {
      clonedList.add(item);
    }
    return clonedList;
  }

  private List<List<Integer>> recurse(ArrayList<Integer> nums, List<List<Integer>> resultsTillNow) {
    if (nums.size() == 0) {
      return resultsTillNow;
    }

    List<List<Integer>> finalResults = new ArrayList<>();
    ArrayList<Integer> clonedNums = (ArrayList)nums.clone();

    for (int i=0; i<nums.size(); ++i) {
      List<List<Integer>> resultsForI = new ArrayList<>();
      int valueAtI = nums.get(i);

      if (resultsTillNow.size() == 0) {
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(valueAtI);
        resultsForI.add(temp);
      }

      for (List<Integer> result: resultsTillNow) {
        List<Integer> clonedResult = clone(result);
        clonedResult.add(valueAtI);
        resultsForI.add(clonedResult);
      }

      clonedNums.remove(i);
      List<List<Integer>> recurseResults = recurse(clonedNums, resultsForI);
      clonedNums.add(i, valueAtI);

      for (List<Integer> recurseResult: recurseResults) {
        finalResults.add(recurseResult);
      }
    }

    return finalResults;
  }

  public List<List<Integer>> permute(int[] nums) {
    List<List<Integer>> results = new ArrayList<>();
    ArrayList<Integer> numsList = new ArrayList<>();

    for (int item: nums) {
      numsList.add(item);
    }

    return recurse(numsList, results);
  }
}
