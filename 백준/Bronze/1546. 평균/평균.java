import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long max = 0;
        long sum = 0;
        int num;
        for (int i=0; i<n; ++i) {
            num = sc.nextInt();
            if (num > max) max = num;
            sum += num;
        }
        System.out.println(sum*100.0/max/n);
    }
}