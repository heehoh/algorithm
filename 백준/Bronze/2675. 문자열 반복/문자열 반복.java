import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            int r = sc.nextInt();
            String s = sc.nextLine().trim();
            StringBuilder sb = new StringBuilder();
            int len = s.length();
            for (int j =0; j < len; ++j) {
                append(sb, s.charAt(j), r);
            }
            answer.append(sb.toString()).append("\n");
        }
        System.out.print(answer);
    }
    public static void append(StringBuilder sb, char c, int r) {
        for (int i =0; i < r; ++i) {
            sb.append(c);
        }
    }
}