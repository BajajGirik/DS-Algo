import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

class Solution {
    private HashMap<String, List<List<Integer>>> memo;

    private List<Integer> insertSortSingleIteration(List<Integer> arr) {
        int element = arr.get(arr.size() - 1);
        int i = arr.size() - 2;

        while(i >= 0) {
            int curr = arr.get(i);
            if (curr < element) {
                break;
            }
            arr.set(i+1, curr);
            --i;
        }

        arr.set(i+1, element);
        return arr;
    }

    private List<List<Integer>> clone(List<List<Integer>> oldArrs) {
        List<List<Integer>> newArrs = new ArrayList<>();

        for (int i=0; i<oldArrs.size(); ++i) {
            List<Integer> oldArr = oldArrs.get(i);
            List<Integer> temp = new ArrayList<>();

            for (int j=0; j<oldArr.size(); ++j) {
                temp.add(oldArr.get(j));
            }

            newArrs.add(temp);
        }

        return newArrs;
    }

    private String getHashKeyForMemo(int index, int target) {
        return index + "," + target;
    }

    private String getHashKeyForArray(List<Integer> arr) {
        String key = "";
        for (int i=0; i<arr.size(); ++i) {
            key += arr.get(i) + ",";
        }
        return key;
    }

    private List<List<Integer>> recurse(int[] candidates, int index, int target) {
        List<List<Integer>> ans = new ArrayList<>();

        String memoKey = this.getHashKeyForMemo(index, target);
        List<List<Integer>> memoised = this.memo.get(memoKey);

        if (memoised != null) {
            return memoised;
        }

        if (target <= 0 || index >= candidates.length) {
          return ans;
        }

        HashSet<String> h = new HashSet<>();

        if (target == candidates[index]) {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(candidates[index]);
            h.add(this.getHashKeyForArray(temp));
            ans.add(temp);
        }

        List<List<Integer>> _a1 = recurse(candidates, index + 1, target - candidates[index]);
        List<List<Integer>> _a2 = recurse(candidates, index + 1, target);
        List<List<Integer>> a1 = this.clone(_a1);
        List<List<Integer>> a2 = this.clone(_a2);

        for (int i=0; i<a1.size(); ++i) {
            List<Integer> l = a1.get(i);
            l.add(candidates[index]);
            l = this.insertSortSingleIteration(l);

            String key = this.getHashKeyForArray(l);
            if (h.contains(key)) {
              continue;
            }

            ans.add(l);
            h.add(key);
        }

        for (int i=0; i<a2.size(); ++i) {
            List<Integer> l = a2.get(i);
            String key = this.getHashKeyForArray(l);
            if (h.contains(key)) {
              continue;
            }
            ans.add(l);
            h.add(key);
        }

        this.memo.put(memoKey, ans);
        return ans;
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        this.memo = new HashMap<>();
        List<List<Integer>> result = recurse(candidates, 0, target);
        return result;
    }
}
