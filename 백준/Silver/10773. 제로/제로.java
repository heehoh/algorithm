import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> s = new Stack<>();
        int k = sc.nextInt();
        while (k-- > 0) {
            int n = sc.nextInt();
            if (n == 0) {
                if (!s.isEmpty())
                s.pop();
            } else {
                s.add(n);
            }
        }
        int num = 0;
        while (!s.isEmpty()) {
            num += s.pop();
        }
        System.out.println(num);
    }
}