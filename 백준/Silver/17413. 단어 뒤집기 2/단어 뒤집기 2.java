import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        boolean isEmb = false;
        boolean isStr = false;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char c = s.charAt(i);
            if (c == '<') {
                if (isStr == true) {
                    sb.append(reverse(s.substring(pos, i)));
                    isStr = false;
                }
                pos = i;
                isEmb = true;
            } else if (c == '>') {
                sb.append(s.substring(pos, i+1));
                isEmb = false;
            } else if (isEmb == false && isStr == true && (c == ' ' || i == len - 1)) {
                if (i != len -1)
                    sb.append(reverse(s.substring(pos, i))).append(" ");
                else
                    sb.append(reverse(s.substring(pos, i+1)));
                isStr = false;
            } else if (isEmb == false && isStr == false && c != ' ') {
                isStr = true;
                pos = i;
            }
        }
        System.out.println(sb);
    }
    public static String reverse(String str) {
        StringBuilder sb = new StringBuilder();
        int len = str.length();
        for (int i = len - 1; i >= 0; --i) {
            sb.append(str.charAt(i));
        }
        return sb.toString();
    }
}