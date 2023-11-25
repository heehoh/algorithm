import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        boolean[] num = new boolean[n+1];
        num[0] = true;
        num[1] = true;
        int number = 0;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; i*j <= n; ++j) {
                if (num[i*j] == false) {
                    num[i*j] = true;
                    ++number;
                    if (number == k) {
                        System.out.println(i*j);
                        return;
                    }
                }
            }
        }
        
    }
}