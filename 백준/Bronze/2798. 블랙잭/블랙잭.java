import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] num = new int[n];
        int m = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            num[i] = sc.nextInt();
        }
        int result = 0;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    int tmp = num[i] + num[j] + num[k];
                    if (tmp == m) {
                        System.out.println(m);
                        return;
                    }
                    if (result < tmp && tmp < m) {
                        result = tmp;
                    }
                }
            }
        }
        System.out.println(result);
    }
}