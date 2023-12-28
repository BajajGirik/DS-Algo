import java.util.ArrayList;
import java.util.List;

class Solution {
    public ArrayList<String> addParenthesis(List<String> results, String parenthesisToAdd) {
        ArrayList<String> finalResults = new ArrayList<>();

        for (int i=0; i<results.size(); ++i) {
            finalResults.add(results.get(i) + parenthesisToAdd);
        }

        return finalResults;
    }

    public ArrayList<String> recurse(int remainingLeftParenthesis, int remainingRightParenthesis, ArrayList<String> computedResults) {
        if (remainingLeftParenthesis == 0 && remainingRightParenthesis == 0) {
            return computedResults;
        }

        ArrayList<String> results = new ArrayList<>();

        if (remainingLeftParenthesis < remainingRightParenthesis) {
            ArrayList<String> resultsAfterAddingRightParenthesis = addParenthesis(computedResults, ")");
            results = recurse(remainingLeftParenthesis, remainingRightParenthesis - 1, resultsAfterAddingRightParenthesis);
        }

        if (remainingLeftParenthesis > 0) {
            ArrayList<String> resultsAfterAddingLeftParenthesis = addParenthesis(computedResults, "(");
            ArrayList<String> tempResults = recurse(remainingLeftParenthesis - 1, remainingRightParenthesis, resultsAfterAddingLeftParenthesis);
            for (int i=0; i<tempResults.size(); ++i) {
                results.add(tempResults.get(i));
            }
        }

        return results;
    }

    public List<String> generateParenthesis(int n) {
        return recurse(n, n, new ArrayList<>(List.of("")));
    }
}
