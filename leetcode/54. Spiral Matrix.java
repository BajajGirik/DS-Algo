import java.util.ArrayList;
import java.util.List;

class Solution {
  public List<Integer> spiralOrder(int[][] matrix) {
    int rowLength = matrix.length;
    int colLength = matrix[0].length;

    int top = -1, bottom = rowLength, left = -1, right = colLength;
    char direction = 'r';

    int i=0, j=0;
    List<Integer> result = new ArrayList<Integer>();

    while (bottom - top != 1 && right - left != 1) {
      result.add(matrix[i][j]);

      switch(direction) {
        case 'r':
          if (j >= right - 1) {
            direction = 'b';
            top++;
            i++;
          } else {
            j++;
          }
          break;
        case 'l':
          if (j <= left + 1) {
            direction = 't';
            bottom--;
            i--;
          } else {
            j--;
          }
          break;
        case 't':
          if (i <= top + 1) {
            direction = 'r';
            left++;
            j++;
          } else {
            i--;
          }
          break;
        case 'b':
          if (i >= bottom - 1) {
            direction = 'l';
            right--;
            j--;
          } else {
            i++;
          }
          break;
        default:
          break;
      }
    }

    return result;
  }
}
