import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] num = new int[10001];
        while (n-- > 0) {
            ++num[Integer.parseInt(br.readLine())];
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 10000; ++i) {
            while (num[i] != 0) {
                sb.append(i).append('\n');
                --num[i];
            }
        }
        System.out.print(sb);
    }
}