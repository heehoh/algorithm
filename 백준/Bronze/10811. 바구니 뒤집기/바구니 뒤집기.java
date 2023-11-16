import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] arr = new int[N];
        for (int i =0; i < N; i++) {
            arr[i] = i+1;
        }
        for (int i=0; i < M; i++) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            while (x < y) {
                swap(arr, x, y);
                ++x;
                --y;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i=0; i < arr.length; i++)
            sb.append(arr[i] + " ");
        System.out.println(sb);
    }
    public static void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}