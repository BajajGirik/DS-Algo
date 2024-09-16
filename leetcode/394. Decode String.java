class Solution {
    private class RecurseResponse {
        public StringBuilder result = new StringBuilder();
        public int index = 0;
    }

    private boolean isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }

    private RecurseResponse recurse(StringBuilder str, int startIndex) {
        RecurseResponse recurseResponse = new RecurseResponse();
        int number = 0, i = startIndex;

        for (; i<str.length(); ++i) {
            char ch = str.charAt(i);
            if (isNumber(ch)) {
                number = number * 10 + (ch - '0');
            } else if (ch == '[') {
                RecurseResponse temp = recurse(str, i+1);
                recurseResponse.result.append(temp.result.toString().repeat(number));
                i = temp.index;
                number = 0;
            } else if (ch == ']') {
                recurseResponse.index = i;
                break;
            } else {
                recurseResponse.result.append(str.charAt(i));
            }
        }

        return recurseResponse;
    }

    public String decodeString(String s) {
        StringBuilder str = new StringBuilder(s);
        RecurseResponse result = recurse(str, 0);
        return result.result.toString();
    }
}
