import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
        }
        int[] score = new int[n];
        for (int i = 0; i < m; ++i) {
            int target = a[i];
            for (int j = 0; j < n; ++j) {
                int b = sc.nextInt();
                if (b == target) {
                    score[j] += 1;
                } else {
                    score[target - 1] += 1;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            System.out.println(score[i]);
    }
}