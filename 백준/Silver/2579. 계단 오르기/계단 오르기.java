import java.util.*;
import java.io.*;

public class Main {
    static int[] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        dp = new int[n];
        int[] stair = new int[n];
        for (int i = 0; i < n; ++i) {
            stair[i] = Integer.parseInt(br.readLine());
        }
        dp[0] = stair[0];
        if (n > 1)
            dp[1] = stair[1] + stair[0];
        if (n > 2)
            dp[2] = stair[2] + Math.max(stair[0], stair[1]);
        for (int i = 3; i < n; ++i)
            dp[i] = stair[i] + Math.max(stair[i - 1] + dp[i - 3], dp[i - 2]);
        System.out.println(dp[n - 1]);
    }
}