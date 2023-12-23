import java.util.*;

public class Main {
    static int n;
    static int r;
    static int c;
    static int ans = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        r = sc.nextInt();
        c = sc.nextInt();
        dc(0,0, (int)Math.pow(2, n));
    }
    public static void dc(int x, int y, int size) {
        if (c == x&& r == y) {
            System.out.println(ans);
            return ;
        }
        else if (c < x + size && r < y + size && c >= x && r >= y) {
            dc(x, y, size / 2);
            dc(x + size/2, y, size / 2);
            dc(x, y + size/2, size/2);
            dc(x + size /2, y + size/2, size /2);
        } else {
            ans += size *size;
        }
    }
}