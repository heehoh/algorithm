import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(fac(sc.nextInt()));
    }
                           
    public static int fac(int n) {
        if (n == 1 || n == 0)
            return 1;
        return n * fac(n - 1);
    }
}