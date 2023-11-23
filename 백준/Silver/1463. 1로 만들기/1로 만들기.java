import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int[] dp = new int[x + 1];
        for (int i = 2; i <= x; ++i) {
            dp[i] = dp[i - 1] + 1;
            if (i % 2 == 0)
                dp[i] = Math.min(dp[i], dp[i/2] + 1);
            if (i % 3 == 0)
                dp[i] = Math.min(dp[i], dp[i/3] + 1);
        }
        System.out.print(dp[x]);
    }
}