import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- > 0) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int r1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            int r2 = sc.nextInt();
            double d = Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
            int bigR, smallR;
            if (r1 > r2) {
                bigR = r1;
                smallR = r2;
            } else {
                bigR = r2;
                smallR = r1;
            }
            if (d == 0 && r1 == r2)
                System.out.println("-1");
            else if (d > r1 + r2 || bigR > smallR + d)
                System.out.println("0");
            else if (d == r1 + r2 || bigR == smallR + d)
                System.out.println("1");
            else
                System.out.println("2");
        }
    }
}