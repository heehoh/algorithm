import java.util.*;

public class Main {
    static char[][] map;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        map = new char[n][2*n-1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(map[i], ' ');
        }
        
        draw(0, n - 1, n);
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2*n-1; ++j) {
                sb.append(map[i][j]);
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }
    public static void draw(int r, int c, int n) {
        if (n == 3) {
            map[r][c] = '*';
            map[r+1][c-1] = map[r+1][c+1] = '*';
            for (int i = c - 2; i <= c+2; ++i)
                map[r+2][i] = '*';
            return ;
        }
            int cut = n / 2;
            draw(r, c, cut);
            draw(r + cut, c - cut, cut);
            draw(r + cut, c + cut, cut);
    }
}