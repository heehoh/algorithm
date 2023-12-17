import java.util.*;

public class Main {
    static ArrayList<Integer>[] com;
    static boolean[] visit;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        visit = new boolean[n + 1];
        com = new ArrayList[n + 1];
        for (int i = 1; i <= n; ++i){
            com[i] = new ArrayList<Integer>();
        }
        int m = sc.nextInt();
        while (m-- > 0) {
            int i = sc.nextInt();
            int j = sc.nextInt();
            com[i].add(j);
            com[j].add(i);
        }
        bfs();
    }
    public static void bfs() {
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        visit[1] = true;
        int n = 0;
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int num : com[i]) {
                if (!visit[num]) {
                    q.add(num);
                    visit[num] = true;
                    ++n;
                }
            }
        }
        System.out.println(n);
    }
}