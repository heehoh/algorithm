import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int min;
        int max;
        int n = sc.nextInt();
        min = sc.nextInt();
        max = min;
        while (--n > 0) {
            int num = sc.nextInt();
            if (min > num)
                min = num;
            if (max < num)
                max = num;
        }
        System.out.println(max * min);
    }
}