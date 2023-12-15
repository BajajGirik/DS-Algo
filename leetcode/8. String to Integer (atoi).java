class Solution {
    public int myAtoi(String s) {
        int start = 0;
        for (start = 0; start < s.length(); ++start) {
            if (s.charAt(start) != ' ') {
                break;
            }
        }

        if (start == s.length()) {
            return 0;
        }

        boolean isNegative = false;
        if (s.charAt(start) == '-') {
            isNegative = true;
            ++start;
        } else if (s.charAt(start) == '+') {
            ++start;
        }

        // Removing zeros present in front...
        for (; start < s.length(); ++start) {
            if (s.charAt(start) != '0') {
                break;
            }
        }

        int maxValue = isNegative ? Integer.MIN_VALUE : -Integer.MAX_VALUE;
        int result = 0;

        for (int i = start; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (ch < '0' || ch > '9') {
                break;
            }

            int digit = ch - '0';
            int _maxValue = (maxValue + digit) / 10;

            if (result < _maxValue) {
                result = maxValue;
                break;
            }

            result *= 10;
            result -= digit;
        }

        return isNegative ? result : -result;
    }
}
