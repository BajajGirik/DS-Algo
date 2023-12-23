class Solution {
    public String convertToTitle(int columnNumber) {
        String result = "";

        while(columnNumber != 0) {
            columnNumber -= 1;
            int charIndex = columnNumber % 26;
            char character = (char)(charIndex + (int)'A');
            result = character + result;
            columnNumber /= 26;
        }

        return result;
    }
}

