import java.util.*;
import java.io.*;

public class Main {
    static long[] d = new long[1000010];
    static int m = 1000000009;

    public static void main(String[] args) throws IOException {
        d[1] = 1;
        d[2] = 2;
        d[3] = 4;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            sb.append(dp(Integer.parseInt(br.readLine()))).append('\n');
        }
        System.out.print(sb);
    }
    static long dp(int i) {
        if (d[i] != 0) 
            return d[i];
        d[i] = dp(i-1)  + dp(i - 2) + dp(i -3);
        d[i] = d[i] % m;
        return d[i];
    }
}