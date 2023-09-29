import java.util.ArrayList;

class Solution {
    ArrayList<Boolean> visited;

    public boolean solve(int[] arr, int index) {
        if (index < 0 || index >= arr.length) {
            return false;
        }

        if (this.visited.get(index)) {
            return false;
        }

        this.visited.set(index, true);
        int val = arr[index];
        if (val == 0) {
            return true;
        }

        return solve(arr, index+val) || solve(arr, index-val);
    }

    public boolean canReach(int[] arr, int start) {
        this.visited = new ArrayList<>();

        for (int i=0; i<arr.length; ++i) {
            this.visited.add(false);
        }

        boolean result = solve(arr, start);
        this.visited = null;
        return result;
    }
}
