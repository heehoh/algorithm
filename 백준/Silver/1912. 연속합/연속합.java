import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] inputs = br.readLine().split(" ");
        int[] num = new int[n];
        int[] dp = new int[n];
        for (int i = 0; i < n; ++i) {
            num[i] = Integer.parseInt(inputs[i]);
        }
        int max = num[0];
        dp[0] = num[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = Math.max(dp[i - 1] + num[i], num[i]);
            max = Math.max(dp[i] , max);
        }
        System.out.println(max);
    }
}