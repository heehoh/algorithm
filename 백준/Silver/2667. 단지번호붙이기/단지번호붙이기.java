import java.util.*;


class Node {
    public int x;
    public int y;
    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int[][] map;
    static boolean[][] visit;
    static int dx[] = {0,0,1,-1};
    static int dy[] = {1,-1,0,0};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        map = new int[n+1][n+1];
        visit = new boolean[n+1][n+1];

        for (int i = 1; i <= n; ++i) {
            String input = sc.next();
            for (int j =1; j <= n; ++j) {
                map[i][j] = input.charAt(j - 1) - '0';
            }
        }
        bfs(n);
    }
    public static void bfs(int n) {
        Queue<Node> q = new LinkedList<>();
        ArrayList<Integer> num = new ArrayList<>();
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <=n; ++j) {
                if (map[i][j] == 1 && visit[i][j] == false) {
                    q.add(new Node(i, j));
                    visit[i][j] = true;
                    int n1 = 1;
                    while (!q.isEmpty()) {
                        Node tmp = q.poll();
                        for (int k=0; k < 4; ++k) {
                            int nx = tmp.x + dx[k];
                            int ny = tmp.y + dy[k];
                            if (nx <= n && nx > 0 && ny <= n && ny > 0) {
                                if (map[nx][ny] == 1 && visit[nx][ny] == false) {
                                    q.add(new Node(nx, ny));
                                    visit[nx][ny] = true;
                                    ++n1;
                                }
                            }
                        }
                    }
                    num.add(n1);
                }
            }
        }
        System.out.println(num.size());
        Collections.sort(num);
        for (int n1 : num) {
            System.out.println(n1);
        }
        
    }
}