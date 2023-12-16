import java.util.HashMap;

class Solution {
    HashMap<Integer, String> createAbnormalIntToRomanMapping() {
        HashMap<Integer, String> INT_TO_ROMAN = new HashMap<>();
        INT_TO_ROMAN.put(4, "IV");
        INT_TO_ROMAN.put(9, "IX");
        INT_TO_ROMAN.put(40, "XL");
        INT_TO_ROMAN.put(90, "XC");
        INT_TO_ROMAN.put(400, "CD");
        INT_TO_ROMAN.put(900, "CM");

        return INT_TO_ROMAN;
    }

    HashMap<Integer, String> createIntToRomanMapping() {
        HashMap<Integer, String> INT_TO_ROMAN = new HashMap<>();
        INT_TO_ROMAN.put(1, "I");
        INT_TO_ROMAN.put(5, "V");
        INT_TO_ROMAN.put(10, "X");
        INT_TO_ROMAN.put(50, "L");
        INT_TO_ROMAN.put(100, "C");
        INT_TO_ROMAN.put(500, "D");
        INT_TO_ROMAN.put(1000, "M");

        return INT_TO_ROMAN;
    }

    public String intToRoman(int num) {
        HashMap<Integer, String> ABNORMAL_INT_TO_ROMAN = this.createAbnormalIntToRomanMapping();
        HashMap<Integer, String> INT_TO_ROMAN = this.createIntToRomanMapping();

        int[] abnormalVals = {4, 4, 9, 40, 90, 400, 900};
        int[] values = {1, 5, 10, 50, 100, 500, 1000};
        String result = "";

        for (int i = values.length - 1; i >= 0; --i) {
            int abnormalVal = abnormalVals[i];
            if (num >= values[i]) {
                int count = num / values[i];
                String val = INT_TO_ROMAN.get(values[i]);

                for (int j=0; j<count; ++j) {
                    result += val;
                }

                num -= count * values[i];
            }
            if (num >= abnormalVal) {
                String val = ABNORMAL_INT_TO_ROMAN.get(abnormalVal);
                result += val;
                num -= abnormalVal;
            }
        }
        return result;
    }
}
