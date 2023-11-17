import java.util.*;

public class Main {
    public static void main(String[] args) {
        int sum = 0;
        Scanner sc = new Scanner(System.in);
        for (int i=0; i < 5; ++i)
            sum += Math.pow(sc.nextInt(), 2);
        System.out.println(sum % 10);
    }
}