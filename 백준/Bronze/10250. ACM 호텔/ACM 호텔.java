import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int H = sc.nextInt();
            int W = sc.nextInt();
            int N = sc.nextInt();
            System.out.println(N % H == 0 ? H*100 + N/H : N%H*100 + N/H +1);
        }
    }
}