import java.util.*;

public class Main {
    static int[] visit = new int[100001];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        bfs(n, k);
    }
    public static void bfs(int n, int k) {
        Queue<Integer> queue = new LinkedList<>();
        
        queue.add(n);
        visit[n] = 1;
        while (!queue.isEmpty()) {
            int a = queue.poll();
            if (a == k) {
                System.out.println(visit[a] - 1);
                return ;
            }
            if (a - 1 >= 0 && visit[a - 1] == 0) {
                queue.add(a - 1);
                visit[a - 1] = visit[a] + 1;
            }
            if (a + 1 <= 100000 && visit[a + 1] == 0) {
                queue.add(a + 1);
                visit[a + 1] = visit[a] + 1;
            }
            if (a * 2 <= 100000 && visit[a * 2] == 0) {
                queue.add(a * 2);
                visit[a * 2] = visit[a] + 1;
            }
        }
    } 
}