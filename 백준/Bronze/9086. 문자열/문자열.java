import java.util.*;

public class Main {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        while (n-- > 0) {
            String s = sc.nextLine();
            sb.append(s.charAt(0)).append(s.charAt(s.length() - 1)).append("\n");
        }
        System.out.println(sb);
    }
}