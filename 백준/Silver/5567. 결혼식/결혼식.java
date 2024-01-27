import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        ArrayList<Integer>[] arr = new ArrayList[n + 1];
        boolean[] visited = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            arr[i] = new ArrayList<>();
        }
        int m = sc.nextInt();
        while (m-- > 0) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            arr[x].add(y);
            arr[y].add(x);
        }
        int num = 0;
        visited[1] = true;
        for (int s : arr[1]) {
            if (visited[s] != true) {
                visited[s] = true;
                ++num;
            }
            for (int k : arr[s]) {
                if (visited[k] != true) {
                    visited[k] = true;
                    ++num;
                }
            }
        }
        System.out.println(num);
    }
}