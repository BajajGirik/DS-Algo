import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
  private List<List<Integer>> permuteHelper(HashMap<Integer, Integer> freqMap) {
    ArrayList<List<Integer>> result = new ArrayList<>();

    for (Map.Entry<Integer, Integer> entry: freqMap.entrySet()) {
      int frequency = entry.getValue();
      if (frequency == 0) {
        continue;
      }

      entry.setValue(frequency - 1);
      List<List<Integer>> currentResult = permuteHelper(freqMap);
      entry.setValue(frequency);

      for (List<Integer> tempList: currentResult) {
        tempList.add(entry.getKey());
        result.add(tempList);
      }
    }

    if (result.size() == 0) {
      ArrayList<Integer> temp = new ArrayList<>();
      result.add(temp);
    }

    return result;
  }

  public List<List<Integer>> permuteUnique(int[] nums) {
    HashMap<Integer, Integer> freqMap = new HashMap<>();

    for (int i=0; i<nums.length; ++i) {
      Integer frequency = freqMap.get(nums[i]);
      if (frequency == null) {
        frequency = 0;
      }
      freqMap.put(nums[i], frequency + 1);
    }

    return permuteHelper(freqMap);
  }
}
