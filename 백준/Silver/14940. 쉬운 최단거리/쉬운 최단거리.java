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
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int[][] map = new int[N][M];
        boolean[][] visit = new boolean[N][M];
        Queue<Node> q = new LinkedList<>();
        for (int i = 0; i < N; ++i) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; ++j) {
                map[i][j] = Integer.parseInt(input[j]);
                if (map[i][j] == 2) {
                    q.add(new Node(i, j));
                    map[i][j] = 0;
                    visit[i][j] = true;
                }
            }
        }
        bfs(map, visit, N, M, q);
    }
    static void bfs(int[][] map, boolean[][] visit, int N, int M, Queue<Node> q) {
        StringBuilder sb = new StringBuilder();
        while (!q.isEmpty()) {
            Node node = q.poll();
            int n = map[node.x][node.y];
            for (int i = 0; i < 4; ++i) {
                int mx = node.x + dx[i];
                int my = node.y + dy[i];
                if (mx < 0 || mx >= N || my < 0 || my >= M || map[mx][my] == 0 || visit[mx][my] == true) {
                    continue;
                }
                q.add(new Node(mx, my));
                visit[mx][my] = true;
                map[mx][my] = n + 1;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                sb.append((visit[i][j] || map[i][j] == 0)? map[i][j] : -1).append(' ');
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
}