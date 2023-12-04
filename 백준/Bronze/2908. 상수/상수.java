import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        int aa = 0;
        int bb = 0;
        while (a != 0) {
            aa = aa * 10 + a % 10;
            a /= 10;
        }
        while (b != 0) {
            bb = bb * 10 + b % 10;
            b /= 10;
        }
        if (aa > bb) System.out.println(aa);
        else System.out.println(bb);
    }
}