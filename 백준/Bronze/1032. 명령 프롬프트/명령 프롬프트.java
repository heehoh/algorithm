import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] strs = new String[n];
        boolean isDiff;
        StringBuilder sb = new StringBuilder();
        for (int i=0; i < n; ++i) {
            strs[i] = sc.nextLine();
        }
        int len = strs[0].length();
        for (int i = 0; i < len; ++i) {
            isDiff = false;
            char c = strs[0].charAt(i);
            for (int j = 1; j < n; ++j) {
                if (c != strs[j].charAt(i)) {
                    isDiff = true;
                    break ;
                }
            }
            if (isDiff == true)
                sb.append('?');
            else
                sb.append(c);
        }
        System.out.println(sb);
    }
}