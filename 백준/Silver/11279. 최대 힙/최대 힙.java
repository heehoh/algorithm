import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Integer> q = new PriorityQueue<>((o1, o2) -> o2-o1);
        int n = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            int a = sc.nextInt();
            if (a == 0)
            {
                if (q.isEmpty()) {
                    sb.append(0).append('\n');
                }
                else
                    sb.append(q.poll()).append('\n');
            }
            else
                q.add(a);
        }
        System.out.println(sb);
    }
}