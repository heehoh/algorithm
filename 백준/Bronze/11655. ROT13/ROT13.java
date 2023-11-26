import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int len = s.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; ++i) {
            char c = s.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                c += 13;
                if (c > 'Z')
                    c = (char)(c - 'Z' + 'A' - 1);
            }
            else if (c >= 'a' && c <= 'z') {
                c += 13;
                if (c > 'z')
                    c = (char)(c - 'z' + 'a' - 1);
            }
            sb.append((char)c);
        }
        System.out.println(sb);
    }
}