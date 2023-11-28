import java.util.*;

public class Main {
    static int[][] dp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        dp = new int[30][30];
        while (n-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            System.out.println(comb(y, x));
        }
    }
    public static int comb(int n, int r) {
        if (dp[n][r] > 0)
            return dp[n][r];
        if (n == r || r == 0)
            return dp[n][r] = 1;
        return dp[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
    }
}