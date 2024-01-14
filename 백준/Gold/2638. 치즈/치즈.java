import java.io.*;
import java.util.*;

class Node {
    int x;
    int y;
    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static Queue<Node> q = new LinkedList<>();
    static Queue<Node> air = new LinkedList<>();
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        char[][] map = new char[n][m];
        for (int i = 0; i < n; ++i) {
            String[] ss = br.readLine().split(" ");
            for (int j = 0; j < m; ++j) {
                map[i][j] = ss[j].charAt(0);
            }
        }

        air.add(new Node(0, 0));
        map[0][0] = '3';
        while (!air.isEmpty()) {
            Node node = air.poll();
            for (int k = 0; k < 4; ++k) {
                int x = node.x + dx[k];
                int y = node.y + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == '0') {
                    map[x][y] = '3';
                    air.add(new Node(x, y));
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == '1') {
                    int a = 0;
                    for (int k = 0; k < 4; ++k) {
                        if (map[i + dx[k]][j + dy[k]] == '3') {
                            ++a;
                        }
                    }
                    if (a > 1) {
                        q.add(new Node(i, j));
                    }
                }
            }
        }
        int day = 0;
        while (!q.isEmpty()) {
            ++day;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node node = q.poll();
                map[node.x][node.y] = '3';
                air.add(new Node(node.x, node.y));
            }
            while (!air.isEmpty()) {
                Node node = air.poll();
                for (int k = 0; k < 4; ++k) {
                    int x = node.x + dx[k];
                    int y = node.y + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == '0') {
                        map[x][y] = '3';
                        air.add(new Node(x, y));
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (map[i][j] == '1') {
                        int a = 0;
                        for (int k = 0; k < 4; ++k) {
                            if (map[i + dx[k]][j + dy[k]] == '3') {
                                ++a;
                            }
                        }
                        if (a > 1) {
                            q.add(new Node(i, j));
                        }
                    }
                }
            }

        }
        System.out.println(day);
    }
}