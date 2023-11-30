import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int n = sc.nextInt();
        sc.nextLine();
        int an = 0;
        while (n-- > 0) {
            if (s.equals(sc.nextLine()))
                ++an;
        }
        System.out.println(an);
    }
}