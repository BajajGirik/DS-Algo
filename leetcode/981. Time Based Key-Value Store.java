import java.util.ArrayList;
import java.util.HashMap;

class TimeMap {
    class Store {
      ArrayList<String> values;
      ArrayList<Integer> timestamps;

      public Store() {
        this.values = new ArrayList<>();
        this.timestamps = new ArrayList<>();
      }
    }

    HashMap<String, Store> keyToStore;

    public TimeMap() {
      this.keyToStore = new HashMap<>();
    }

    private void performSingleInsertionSortPass(
      ArrayList<Integer> timestamps,
      ArrayList<String> values
    ) {
      int i = timestamps.size() - 2;
      int lastTimestamp = timestamps.get(i + 1);
      String lastValue = values.get(i + 1);

      while (i >= 0) {
        int current = timestamps.get(i);

        if (current <= lastTimestamp) {
          break;
        }

        timestamps.set(i+1, current);
        values.set(i+1, values.get(i));
        --i;
      }

      timestamps.set(i+1, lastTimestamp);
      values.set(i+1, lastValue);
    }
    
    public void set(String key, String value, int timestamp) {
      Store store = this.keyToStore.get(key);

      if (store == null) {
        store = new Store();
        this.keyToStore.put(key, store);
      }

      store.values.add(value);
      store.timestamps.add(timestamp);

      this.performSingleInsertionSortPass(
        store.timestamps,
        store.values
      );

    }
    
    private int binarySearch(ArrayList<Integer> timestamps, int target) {
      int start = 0;
      int end = timestamps.size() - 1;

      while (start <= end) {
        int mid = (start + end) / 2;

        int midTimestamp = timestamps.get(mid);

        if (midTimestamp == target) {
          return mid;
        }

        if (midTimestamp > target) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      }

      return end;
    }

    public String get(String key, int timestamp) {
      Store store = this.keyToStore.get(key);
      if (store == null) {
        return "";
      }

      int index = this.binarySearch(store.timestamps, timestamp);
      if (index < 0) {
        return "";
      }

      return store.values.get(index);
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */

