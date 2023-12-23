class Solution {
    public int power(int base, int exponent) {
        int result = 1;

        for (int i=0; i<exponent; ++i) {
            result *= base;
        }

        return result;
    }

    public int titleToNumber(String columnTitle) {
        int len = columnTitle.length();
        int result = 0;

        for (int i=0; i<len; ++i) {
            int val = columnTitle.charAt(i) - 'A' + 1;
            result += val * this.power(26, len - i - 1);
        }

        return result;
    }
}
