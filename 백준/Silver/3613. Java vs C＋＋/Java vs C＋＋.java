import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        boolean c = false;
        boolean java = false;
        boolean error = false;
        int len = s.length();
        
        for (int i=0; i < len; ++i) {
            char ch = s.charAt(i);
            if (ch == '_') {
                c = true;
                if (i == 0 || s.charAt(i-1) == '_' || i == len - 1) {
                    error = true;
                    break ;
                }
            }
            else if (ch <= 'Z') {
                java = true;
                if (i == 0) {
                    error = true;
                    break;
                }
            }
        }
        if ((c == true && java == true) || error == true) {
            System.out.println("Error!");
            return ;
        }
        else if (c == true)
            s = convertJava(s);
        else if (java == true)
            s = convertC(s);
       System.out.println(s);
    }
    
    public static String convertJava(String s) {
        int len = s.length();
        StringBuilder sb = new StringBuilder();
        for (int i=0; i < len; ++i) {
            char c = s.charAt(i);
            if (c == '_') {
                sb.append((char)(s.charAt(++i) + 'A' - 'a'));
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
    public static String convertC(String s) {
        int len = s.length();
        StringBuilder sb = new StringBuilder();
        for (int i=0; i <len; ++i) {
            char c = s.charAt(i);
            if (c <= 'Z') {
                sb.append('_').append((char)(c - 'A' + 'a'));
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}