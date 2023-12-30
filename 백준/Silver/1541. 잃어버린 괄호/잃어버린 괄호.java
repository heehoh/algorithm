import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int sum = 0;
        int minus = 0;
        boolean isMinus = false;
        int a = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '+') {
                if (isMinus == false) {
                    sum += a;
                    a = 0;
                } else {
                    minus += a;
                    a = 0;
                }
            }
            else if (c == '-') {
                if (isMinus == false) {
                    sum += a;
                    a = 0;
                } else {
                    minus += a;
                    a = 0;
                }
                isMinus = true;
            } else {
                a *= 10;
                a += c - '0';
            }
        }
        if (isMinus) {
            minus +=a;
        } else {
            sum += a;
        }
        System.out.println(sum - minus);
    }
}