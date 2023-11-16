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
            int x = sc.nextInt();
            int y = sc.nextInt();
            for (int j=0; j<(y-x+1)/2; ++j){
                swap(arr, x - 1 + j, y - 1 -j);
            }
        }
        for (int i=0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }
    public static void swap(int[] a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}