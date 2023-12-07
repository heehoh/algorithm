import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int n = sc.nextInt();
        
        int c = a % b;
        while (--n > 0) {
            c *= 10;
            c %= b;
        }
        c *= 10;
        System.out.println(c/b);
    }
}