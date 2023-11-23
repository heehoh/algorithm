import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int len = getLen(n);
        int a = 0;
        for (int i = n - 9 * len; i < n; ++i) {
            if (n == i + rec(i)) {
                a = i;
                break;
            }
        }
        System.out.println(a);
    }
    public static int rec(int i) {
        if (i == 0)
            return 0;
        return rec(i /10) + i%10;
    }
    public static int getLen(int n) {
        int len = 0;
        while (n != 0) {
            n /= 10;
            ++len;
        }
        return len;
    }
}