import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = 0;
        for (int i = 1; i < n; ++i) {
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
}