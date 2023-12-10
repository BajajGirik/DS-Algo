class Solution {
    public String convert(String s, int numRows) {
        if (s.length() <= numRows || numRows == 1) {
            return s;
        }

        int columnIncrementor = 2 * numRows - 2;
        int diagonalIncrementor = 2 * numRows - 2;
        String result = "";

        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.length(); j += columnIncrementor) {
                result += s.charAt(j);
                if (i != 0 && i != numRows - 1 && j + diagonalIncrementor < s.length())
                    result += s.charAt(j + diagonalIncrementor);
            }
            diagonalIncrementor -= 2;
        }

        return result;
    }
}
