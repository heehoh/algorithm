import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] days = new int[20];
        int[] moneys = new int[20];
        int[] dp = new int[20];
        for (int i = 0; i < n; ++i) {
            String[] input = br.readLine().split(" ");
            days[i] = Integer.parseInt(input[0]);
            moneys[i] = Integer.parseInt(input[1]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (days[i] + i > n) {
                dp[i] = dp[i + 1];
            } else {
                dp[i] = Math.max(dp[i + days[i]] + moneys[i], dp[i + 1]);
            }
            
        }
        System.out.println(dp[0]);
    }
}