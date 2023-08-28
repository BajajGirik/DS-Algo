import java.util.LinkedList;
import java.util.Queue;

class LongestCommonPrefix {
    class Node {
        Node children[];
        int childrenCount;
        boolean eow;

        public Node() {
            this.childrenCount = 0;
            this.eow = false;
            this.children = new Node[26];
            for (int i=0; i<26; ++i) {
                this.children[i] = null;
            }
        }
    }

    public Node createTrie(String[] strs) {
        Node head = new Node();

        for (int i=0; i<strs.length; ++i) {
            String currStr = strs[i];
            Node curr = head;

            for (int j = 0; j < currStr.length(); ++j) {
                int charIndex = currStr.charAt(j) - 'a';
                if (curr.children[charIndex] == null) {
                    curr.children[charIndex] = new Node();
                    ++curr.childrenCount;
                }
                curr = curr.children[charIndex];
            }
            curr.eow = true;
        }

        return head;
    }

    public String getCommonPrefixFromTrie(Node head) {
        Node curr = head;
        StringBuilder str = new StringBuilder();

        while (!curr.eow && curr.childrenCount == 1) {
            for (int i = 0; i < 26; ++i) {
                if (curr.children[i] == null) {
                    continue;
                }

                char currChar = (char)(i + (int)'a');
                str.append(currChar);
                curr = curr.children[i];
                break;
            }
        }

        return str.toString();
    }

    public void printTrie(Node head) {
        Queue<Node> q = new LinkedList<>();
        q.add(head);
        q.add(null);
        while(!q.isEmpty()) {
            Node curr = q.remove();
            if (curr == null) {
                System.out.println("");
                if (!q.isEmpty()) {
                    q.add(null);
                }
                continue;
            }

            for (int i = 0; i < 26; ++i) {
                if (curr.children[i] != null) {
                  char currChar = (char)(i + (int)'a');
                  System.out.print(currChar + " ");
                  q.add(curr.children[i]);
                }
            }
        }
    }

    public String longestCommonPrefix(String[] strs) {
        Node head = createTrie(strs);
        return getCommonPrefixFromTrie(head);
    }
}
