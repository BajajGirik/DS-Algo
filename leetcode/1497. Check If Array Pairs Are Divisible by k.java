import java.util.ArrayList;

class Solution {
    public boolean canArrangeTLE(int[] arr, int k) {
        boolean found[] = new boolean[arr.length];
        for (int i=0; i<arr.length; ++i) {
            found[i] = false;
        }

        for (int i=0; i<arr.length-1; ++i) {
            if (found[i]) {
                continue;
            }

            for (int j=i+1; j<arr.length; ++j) {
                if (found[j]) {
                    continue;
                }

                if ((arr[i] + arr[j]) % k == 0) {
                    found[i] = true;
                    found[j] = true;
                    break;
                }
            }

            if (!found[i]) {
                return false;
            }
        }

        return true;
    }

    public boolean canArrange(int[] arr, int k) {
        int freq[] = new int[k];

        for (int i=0; i<arr.length; ++i) {
            int f = arr[i] % k;
            if (f >= 0) {
                freq[f]++;
            } else {
                freq[k + f]++;
            }
        }


        for (int i=1, j=k-1; i<j; ++i, --j) {
            if (freq[i] != freq[j]) {
                return false;
            }
        }

        // Checking for i == j case
        if (k % 2 == 0 && freq[k/2] % 2 != 0) {
            return false;
        }

        return true;
    }
}
