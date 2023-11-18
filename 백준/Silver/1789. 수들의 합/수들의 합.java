import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        long sum = sc.nextLong();
        int x = 1;
        int count = 0;
        while (sum != 0) {
            sum -= x;
            if (sum < 0)
                break;
            ++x;
            ++count;
        }
        System.out.println(count);
    }
}