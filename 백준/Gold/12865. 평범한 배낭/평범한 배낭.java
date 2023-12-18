import java.util.*;

public class Main {
    static int[] w;
    static int[] v;
    static int[][] dp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        w = new int[n + 1];
        v = new int[n + 1];
        dp = new int[n + 1][k + 1];
        
        for (int i = 1; i <= n; ++i) {
            w[i] = sc.nextInt();
            v[i] = sc.nextInt();
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (w[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        System.out.println(dp[n][k]);
    }
}