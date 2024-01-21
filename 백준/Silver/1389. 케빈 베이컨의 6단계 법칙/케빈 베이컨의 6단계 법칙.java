import java.util.*;
import java.io.*;

public class Main {
    static int k, n;
    static ArrayList<Integer>[] graph;
    static int[] dist;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nums = br.readLine().split(" ");
        k = Integer.parseInt(nums[0]);
        n = Integer.parseInt(nums[1]);
        dist = new int[k + 1];
        graph = new ArrayList[k + 1];
        
        for (int i = 1; i <= k; ++i) {
            graph[i] = new ArrayList<>();
        }
        
        while (n-- > 0) {
            nums = br.readLine().split(" ");
            int a = Integer.parseInt(nums[0]);
            int b = Integer.parseInt(nums[1]);
            graph[a].add(b);
            graph[b].add(a);
        }
        solution();
    }
    
    static void solution() {
        int min = Integer.MAX_VALUE, minIdx = 0;
        for (int i = 1; i <= k; ++i) {
            int cnt = bfs(i);
            if (min > cnt) {
                min = cnt;
                minIdx = i;
            }
        }
        System.out.println(minIdx);
    }
    
    static int bfs(int start) {
        Arrays.fill(dist, -1);
        int cnt = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        dist[start] = 0;
        while (!q.isEmpty()) {
            int x = q.poll();
            for (int y : graph[x]) {
                if (dist[y] != -1) continue;
                dist[y] = dist[x] + 1;
                cnt += dist[y];
                q.add(y);
            }
        }
        return cnt;
     }
}