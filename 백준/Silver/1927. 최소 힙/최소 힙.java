import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        PriorityQueue<Integer> q = new PriorityQueue<>();
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            int num = sc.nextInt();
            if (num == 0) {
                if (!q.isEmpty())
                    sb.append(q.poll()).append('\n');
                else
                    sb.append(0).append('\n');
            }
            else {
                q.add(num);
            }
        }
        System.out.println(sb);
    }
}