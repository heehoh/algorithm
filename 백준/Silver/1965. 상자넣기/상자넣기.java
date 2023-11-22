import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1];
        int[] d = new int[n+1];
        
        a[0] = 0;
        d[0] = 0;
        int max = 0;
        for (int i=1; i < n+1; ++i) {
            a[i] = sc.nextInt();
            d[i] = count(a, d, i);
            if (max < d[i])
                max = d[i];
        }
        System.out.println(max);
    }
    
    public static int count(int[] a, int[] d, int idx) {
        int val = a[idx];
        int p = 0;
        for (int i=0; i < idx; ++i) {
            if (a[i] < val) {
                if (d[p] < d[i])
                    p = i;
            }
        }
        return d[p] + 1;
    }
}