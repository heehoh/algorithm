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
    static int r;
    static int c;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        r = sc.nextInt();
        c = sc.nextInt();
        sc.nextLine();
        String[] s = new String[r];
        int[][] visit = new int[r][c];
        int[][] fvisit = new int[r][c];
        
        for (int i = 0; i < r; ++i) {
            s[i] = sc.nextLine();
        }
        
        bfs(s, visit, fvisit);
    }
    
    public static void bfs(String[] s, int[][] visit, int[][] fvisit) {
        Queue<Node> man = new LinkedList<>();
        Queue<Node> fire = new LinkedList<>();
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (s[i].charAt(j) == 'J') {
                    man.add(new Node(i, j));
                    visit[i][j] = 1;
                } 
                else if (s[i].charAt(j) == 'F') {
                    fire.add(new Node(i, j));
                    fvisit[i][j] = 1;
                }
            }
        }
        
        while (!man.isEmpty()) {
            if (!fire.isEmpty()) {
                int fireSize = fire.size();
                for (int k = 0; k < fireSize; k++) {
                    Node f = fire.poll();
                    
                    for (int i = 0; i < 4; ++i) {
                        int fx = f.x + dx[i];
                        int fy = f.y + dy[i];
                        
                        if (fx >= 0 && fx < r && fy >= 0 && fy < c && s[fx].charAt(fy) != '#' && fvisit[fx][fy] == 0) {
                            fire.add(new Node(fx, fy));
                            fvisit[fx][fy] = 1;
                        }
                    }
                }
            }

            int manSize = man.size();
            for (int k = 0; k < manSize; ++k) {
                Node m = man.poll();
            
                for (int i = 0; i < 4; ++i) {
                    int mx = m.x + dx[i];
                    int my = m.y + dy[i];
                
                    if (mx < 0 || mx == r || my < 0 || my == c) {
                        System.out.println(visit[m.x][m.y]);
                        return;
                    }
                
                    if (visit[mx][my] == 0 && s[mx].charAt(my) != '#' && fvisit[mx][my] == 0) {
                        man.add(new Node(mx, my));
                        visit[mx][my] = visit[m.x][m.y] + 1;
                    }
                }
            }   

        }
        System.out.println("IMPOSSIBLE");
    }
}