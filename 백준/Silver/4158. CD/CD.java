import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            String[] str = br.readLine().split(" ");
            int n = Integer.parseInt(str[0]);
            int m = Integer.parseInt(str[1]);
            if (n == 0 && m == 0)
                break;
            int[] arr1 = new int[n];
            int[] arr2 = new int[m];
            for (int i = 0; i < n; ++i)
                arr1[i] = Integer.parseInt(br.readLine());
            for (int i = 0; i < m; ++i)
                arr2[i] = Integer.parseInt(br.readLine());
            int num = 0;
            int i = 0, j = 0;
            while (i != n && j != m) {
                if (arr1[i] == arr2[j]) {
                    ++num;
                    ++i;
                    ++j;
                }
                else if (arr1[i] > arr2[j])
                    ++j;
                else
                    ++i;
            }
            System.out.println(num);
        }
    }
}