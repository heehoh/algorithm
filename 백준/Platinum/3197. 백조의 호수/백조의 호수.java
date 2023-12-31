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
    static Queue<Node> swanQ;
    static Queue<Node> meltQ;
    static int r;
    static int c;
    static char[][] map;
    static boolean[][] visit;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        swanQ = new LinkedList<>();
        meltQ = new LinkedList<>();
        r = sc.nextInt();
        c = sc.nextInt();
        sc.nextLine();
        map = new char[r][];
        visit = new boolean[r][c];
        for (int i = 0; i < r; ++i) {
            map[i] = sc.nextLine().toCharArray();
        }
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == 'L') {
                    swanQ.add(new Node(i, j));
                    visit[i][j] = true;
                    break ;
                }
            }
            if (swanQ.size() != 0)
                break ;
        }

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (map[i][j] == '.' || map[i][j] == 'L') {
                    meltQ.add(new Node(i, j));
                }
            }
        }
        int day = 0;
        while (bfs()) {
            melt();
            ++day;
        }
        System.out.println(day);
    }
    
    public static boolean bfs() {
        Queue<Node> nextQ = new LinkedList<>();
        while (!swanQ.isEmpty()) {
            Node tmp = swanQ.poll();
            for (int i = 0; i < 4; ++i) {
                int x = tmp.x + dx[i];
                int y = tmp.y + dy[i];
                if (x >= 0 && x < r && y >= 0 && y < c && !visit[x][y]) {
                    if (map[x][y] == 'L')
                        return false;
                    visit[x][y] = true;
                    if (map[x][y] == '.') {
                        swanQ.add(new Node(x, y));
                    }
                    else if (map[x][y] == 'X') {
                        nextQ.add(new Node(x, y));
                    }
                }
            }
        }
        swanQ = nextQ; // 큐를 교체
        return true;
    }

    public static void melt() {
        int size = meltQ.size();
        for (int i = 0; i < size; ++i) {
            Node tmp = meltQ.poll();
            for (int k = 0; k < 4; ++k) {
                int x = tmp.x + dx[k];
                int y = tmp.y + dy[k];
                if (x >= 0 && x < r && y >= 0 && y < c) {
                    if (map[x][y] == 'X') {
                        map[x][y] = '.';
                        meltQ.add(new Node(x, y));
                    }
                }
            }
        }
    }
}