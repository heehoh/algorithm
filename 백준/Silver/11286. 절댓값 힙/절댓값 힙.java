import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Integer> plus = new PriorityQueue<>();
        PriorityQueue<Integer> minus = new PriorityQueue<>((o1, o2) -> o2-o1);
        int n = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            int a = sc.nextInt();
            if (a == 0) {
                if (minus.isEmpty()) {
                    if (plus.isEmpty()) {
                        sb.append(0).append('\n');
                        continue;
                    }
                    sb.append(plus.poll()).append('\n');
                    continue;
                }
                if (plus.isEmpty()) {
                    sb.append(minus.poll()).append('\n');
                    continue;
                }
                int num = minus.peek();
                num *= -1;
                if (num <= plus.peek()) {
                    sb.append(minus.poll()).append('\n');
                } else {
                    sb.append(plus.poll()).append('\n');
                }
            } else if (a < 0)
                minus.add(a);
            else
                plus.add(a);
        }
        System.out.print(sb);
    }
}