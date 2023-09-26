class Solution {
    public int[] decrypt(int[] code, int k) {
        int res[] = new int[code.length];

        if (k == 0) {
            return res;
        }

        int sum = 0;
        if (k > 0) {
            for (int i=1; i<k+1; ++i) {
                sum += code[i];
            }

            for(int i=0; i<code.length; ++i) {
                res[i] = sum;
                sum += code[(i+k+1) % code.length] - code[(i+1) % code.length];
            }
        } else {
            for (int i=code.length+k; i<code.length; ++i) {
                sum += code[i];
            }

            for(int i=0; i<code.length; ++i) {
                res[i] = sum;
                sum += code[i] - code[(2*code.length + k + i) % code.length];
            }
        }

        return res;
    }
}
