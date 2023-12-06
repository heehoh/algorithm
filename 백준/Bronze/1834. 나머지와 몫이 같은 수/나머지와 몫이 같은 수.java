import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long sum = 0;
        for (long i = 1; i < n; ++i) {
            sum += i * (n + 1);
        }
        System.out.println(sum);
    }
}