import java.util.*;
import java.io.*;

class Node {
    int x;
    int y;
    
    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int N, T;
    static Node[] graph;
    static int[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        T = Integer.parseInt(str[1]);
        graph = new Node[N + 1];
        visited = new int[N + 1];
        graph[0] = new Node(0, 0);
        for (int i = 1; i <= N; ++i) {
            str = br.readLine().split(" ");
            int x = Integer.parseInt(str[0]);
            int y = Integer.parseInt(str[1]);
            graph[i] = new Node(x, y);
        }
        Arrays.sort(graph, (o1, o2) -> {
            if (o1.y > o2.y) {
                return 1;
            } else if (o1.y == o2.y && o1.x > o2.x) {
                return 1;
            }
            return -1;
        });
        System.out.println(bfs());
    }
    public static int bfs() {
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        visited[0] = 0;

        while (!q.isEmpty()) {
            int idx = q.poll();
            if (graph[idx].y == T) {
                return visited[idx];
            }
            int x = graph[idx].x;
            int y = graph[idx].y;
            // 올라갈 때
            for (int i = idx + 1; i <= N; ++i) {
                if (visited[i] != 0) {
                    continue;
                }
                if (graph[i].y - y > 2) {
                    break;
                }
                if (Math.abs(graph[i].x - x) > 2) {
                    continue;
                }
                q.add(i);
                visited[i] = visited[idx] + 1;
            }
            // 내려갈 때
            for (int i = idx - 1; i > 0; --i) {
                if (visited[i] != 0) {
                    continue;
                }
                if (graph[i].y - y < -2) {
                    break;
                }
                if (Math.abs(graph[i].x - x) > 2) {
                    continue;
                }
                q.add(i);
                visited[i] = visited[idx] + 1;
            }
        }
        return -1;
    }
}