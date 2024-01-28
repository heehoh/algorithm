import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] str = br.readLine().split(" ");
        int[] num = new int[n];
        for (int i = 0; i < n; ++i) {
            num[i] = Integer.parseInt(str[i]);
        }
        Arrays.sort(num);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += num[i] * (n - i);
        }
        System.out.println(sum);
    }
}