import java.util.Scanner;

public class ArrayColoring {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();
        sc.nextLine();

        while(tests-- != 0) {
            int n = sc.nextInt();
            sc.nextLine();

            int odds = 0;

            for (int i=0; i<n; ++i) {
                int x = sc.nextInt();
                if (x % 2 == 1) {
                    ++odds;
                }
            }

            if (odds % 2 == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            sc.nextLine();
        }

        sc.close();
    }
}
