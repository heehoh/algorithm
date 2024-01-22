import java.util.*;

public class Main {
    static int[] dp = new int[1000001];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        for (int i = 4; i <= n; ++i) {
            if (i % 3 == 0) {
                dp[i] = 1 + dp[i / 3];
            }
            if (i % 2 == 0 && (dp[i] == 0 || dp[i] > dp[i / 2] + 1)) {
                dp[i] = 1 + dp[i / 2];
            }
            if (dp[i] == 0 || dp[i] > dp[i - 1] + 1)
                dp[i] = 1 + dp[i - 1];
        }
        System.out.println(dp[n]);
        solution(n);
    }
    
    static void solution(int n) {
        StringBuilder sb = new StringBuilder();
        while (n != 1) {
            sb.append(n).append(' ');
            int tmp = 0;
            if (n % 3 == 0) {
                tmp = n / 3;
            }
            if (n % 2 == 0) {
                if (tmp == 0 || dp[tmp] > dp[n / 2]) {
                    tmp = n / 2;
                }
            }
            if (tmp == 0 || dp[tmp] > dp[n - 1]) {
                tmp = n - 1;
            }
            n = tmp;
        }
        sb.append(n).append('\n');
        System.out.print(sb);
    }
}