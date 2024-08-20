import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
      Stack<String> stack = new Stack<>();

      for (int i=0; i<s.length(); ++i) {
        char ch = s.charAt(i);
        
        if (ch != 'a' && stack.isEmpty()) {
          return false;
        }

        if (ch == 'a') {
          stack.push("a");
        } else if (ch == 'b') {
          String result = stack.pop();
          if (result != "a") {
            return false;
          }

          stack.push("ab");
        } else {
          String result = stack.pop();
          if (result != "ab") {
            return false;
          }
        }
      }

      return stack.size() == 0;
    }
}
