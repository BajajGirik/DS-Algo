import java.util.HashMap;

class Solution {
    HashMap<String, Integer> createRomanToIntMapping() {
        HashMap<String, Integer> ROMAN_TO_INT = new HashMap<>();
        ROMAN_TO_INT.put("I", 1);
        ROMAN_TO_INT.put("V", 5);
        ROMAN_TO_INT.put("X", 10);
        ROMAN_TO_INT.put("L", 50);
        ROMAN_TO_INT.put("C", 100);
        ROMAN_TO_INT.put("D", 500);
        ROMAN_TO_INT.put("M", 1000);

        return ROMAN_TO_INT;
    }

    public int romanToInt(String s) {
        if (s.length() == 0) {
            return 0;
        }

        HashMap<String, Integer> ROMAN_TO_INT = createRomanToIntMapping();
        int result = 0;
        int prev = ROMAN_TO_INT.get(String.valueOf(s.charAt(0)));

        for (int i=1; i<s.length(); ++i) {
            int curr = ROMAN_TO_INT.get(String.valueOf(s.charAt(i)));
            if (prev < curr) {
                result -= prev;
            } else {
                result += prev;
            }
            prev = curr;
        }

        String lastChar = String.valueOf(s.charAt(s.length() - 1));
        result += ROMAN_TO_INT.get(lastChar);
        return result;
    }
}
