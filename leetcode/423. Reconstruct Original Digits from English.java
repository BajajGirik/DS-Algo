import java.util.HashMap;

class Solution {
  public String originalDigits(String s) {
    HashMap<Character, Integer> charFrequency = new HashMap<>();

    for (int i = 0; i < s.length(); ++i) {
      char ch = s.charAt(i);
      Integer freq = charFrequency.get(ch);
      if (freq == null) {
        freq = 0;
      }
      charFrequency.put(ch, freq + 1);
    }

    Integer zerofreq = charFrequency.get('z');
    if (zerofreq != null && zerofreq != 0) {
      charFrequency.remove('z');
      charFrequency.put('e', charFrequency.get('e') - zerofreq);
      charFrequency.put('r', charFrequency.get('r') - zerofreq);
      charFrequency.put('o', charFrequency.get('o') - zerofreq);
    }

    Integer twofreq = charFrequency.get('w');
    if (twofreq != null && twofreq != 0) {
      charFrequency.remove('w');
      charFrequency.put('t', charFrequency.get('t') - twofreq);
      charFrequency.put('o', charFrequency.get('o') - twofreq);
    }

    Integer fourfreq = charFrequency.get('u');
    if (fourfreq != null && fourfreq != 0) {
      charFrequency.remove('u');
      charFrequency.put('f', charFrequency.get('f') - fourfreq);
      charFrequency.put('o', charFrequency.get('o') - fourfreq);
      charFrequency.put('r', charFrequency.get('r') - fourfreq);
    }

    Integer sixfreq = charFrequency.get('x');
    if (sixfreq != null && sixfreq != 0) {
      charFrequency.remove('x');
      charFrequency.put('s', charFrequency.get('s') - sixfreq);
      charFrequency.put('i', charFrequency.get('i') - sixfreq);
    }

    Integer eightfreq = charFrequency.get('g');
    if (eightfreq != null && eightfreq != 0) {
      charFrequency.remove('g');
      charFrequency.put('e', charFrequency.get('e') - eightfreq);
      charFrequency.put('i', charFrequency.get('i') - eightfreq);
      charFrequency.put('h', charFrequency.get('h') - eightfreq);
      charFrequency.put('t', charFrequency.get('t') - eightfreq);
    }

    Integer onefreq = charFrequency.get('o');
    if (onefreq != null && onefreq != 0) {
      charFrequency.remove('o');
      charFrequency.put('n', charFrequency.get('n') - onefreq);
      charFrequency.put('e', charFrequency.get('e') - onefreq);
    }

    Integer threefreq = charFrequency.get('t');
    if (threefreq != null && threefreq != 0) {
      charFrequency.remove('t');
      charFrequency.put('h', charFrequency.get('h') - threefreq);
      charFrequency.put('r', charFrequency.get('r') - threefreq);
      charFrequency.put('e', charFrequency.get('e') - 2 * threefreq);
    }

    Integer fivefreq = charFrequency.get('f');
    if (fivefreq != null && fivefreq != 0) {
      charFrequency.remove('f');
      charFrequency.put('i', charFrequency.get('i') - fivefreq);
      charFrequency.put('v', charFrequency.get('v') - fivefreq);
      charFrequency.put('e', charFrequency.get('e') - fivefreq);
    }

    Integer sevenfreq = charFrequency.get('s');
    if (sevenfreq != null && sevenfreq != 0) {
      int freq = charFrequency.get('s');
      charFrequency.remove('s');
      charFrequency.put('e', charFrequency.get('e') - 2 * sevenfreq);
      charFrequency.put('v', charFrequency.get('v') - sevenfreq);
      charFrequency.put('n', charFrequency.get('n') - sevenfreq);
    }

    Integer ninefreq = charFrequency.get('i');
    if (ninefreq != null && ninefreq != 0) {
      charFrequency.remove('i');
      charFrequency.put('n', charFrequency.get('n') - 2 * ninefreq);
      charFrequency.put('e', charFrequency.get('e') - ninefreq);
    }

    String result = "";
    Integer[] nums = new Integer[] {zerofreq, onefreq, twofreq, threefreq, fourfreq, fivefreq, sixfreq, sevenfreq, eightfreq, ninefreq};

    for (int i=0; i<=9; ++i) {
      if (nums[i] != null) {
        result += String.valueOf(i).repeat(nums[i]);
      }
    }
    return result;
  }
}

// one
// three
// five
// seven
// nine
//
// zero -> z
// two -> w
// four -> u
// six -> x
// eight -> g
