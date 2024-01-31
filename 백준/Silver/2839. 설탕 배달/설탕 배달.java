import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] dp = new int[5001];
        dp[1] = -1;
        dp[2] = -1;
        dp[3] = 1;
        dp[4] = -1;
        dp[5] = 1;
        for (int i = 6; i <= n; ++i) {
            if (dp[i - 3] > 0 && dp[i - 5] > 0) {
                dp[i] = Math.min(dp[i-3], dp[i-5]) + 1;
            } else if (dp[i -3] > 0) {
                dp[i]= dp[i -3] + 1;
            } else if (dp[i - 5] > 0) {
                dp[i] = dp[i - 5] + 1;
            } else {
                dp[i] = -1;
            }
        }
        System.out.println(dp[n]);
    }
}