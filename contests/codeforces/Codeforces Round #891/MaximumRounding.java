import java.util.Scanner;

public class MaximumRounding {
    public static void solve(String num) {
        int ind = -1;
        int carry = 0;

        for (int i=num.length() - 1; i >= 0; --i) {
            int curr = num.charAt(i) - '0';
            if (curr + carry >= 5) {
                carry = 1;
                ind = i;
            } else {
                carry = 0;
            }
        }

        if (ind == -1) {
            System.out.println(num);
            return;
        }

        for (int i=0; i<ind-1; ++i) {
            System.out.print(num.charAt(i));
        }

        if (ind == 0) {
            System.out.print(1);
        } else {
            int curr = num.charAt(ind-1) - '0';
            System.out.print(curr + 1);
        }

        for (int i=ind; i<num.length(); ++i) {
            System.out.print(0);
        }

        System.out.println();
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();

        while(tests-- != 0) {
            String num = sc.next();
            solve(num);
        }

        sc.close();
    }
}
