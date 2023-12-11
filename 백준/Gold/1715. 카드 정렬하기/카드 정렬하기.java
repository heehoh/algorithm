import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PriorityQueue<Integer> q = new PriorityQueue<>();
        while (n-- > 0)
            q.add(sc.nextInt());
        int sum = 0;
        while (q.size() > 1) {
            int num = q.poll() + q.poll();
            q.add(num);
            sum += num;
        }
        System.out.println(sum);
    }
}