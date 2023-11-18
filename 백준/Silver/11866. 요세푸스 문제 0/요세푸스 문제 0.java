import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Queue<Integer> q = new LinkedList<>();
        for (int i=0; i < n; ++i) {
            q.add(i+1);
        }
        StringBuilder sb = new StringBuilder("<");
        while (!q.isEmpty()) {
            int count = 0;
            while (count < k-1) {
                ++count;
                q.add(q.poll());
            }
            sb.append(q.poll());
            if (!q.isEmpty())
                sb.append(", ");
        }
        sb.append(">");
        System.out.println(sb);
    }
}