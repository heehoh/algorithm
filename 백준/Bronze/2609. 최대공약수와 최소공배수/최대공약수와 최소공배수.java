import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int k = 1;
        int s = n > m ? n : m;
        for (int i = 1; i <= n && i <= m; ++i) {
            if (n % i == 0 && m % i == 0)
                k = i;
        }
        System.out.println(k);
        while (true) {
            if (s % n == 0 && s % m == 0)
                break;
            ++s;
        }
        System.out.println(s);
    }
}