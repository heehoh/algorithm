import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        LinkedList<Integer> d = new LinkedList<>();
        for (int i = 1; i <= n; ++i) {
            d.offer(i);
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            int target = d.indexOf(sc.nextInt());
            int half = d.size() / 2 + d.size() % 2 - 1;
            
            if (target <= half) {
                for (int j = 0; j < target; ++j) {
                    d.offerLast(d.pollFirst());
                    ++cnt;
                }
            } else {
                for (int j = 0; j < d.size() - target; ++j) {
                    d.offerFirst(d.pollLast());
                    ++cnt;
                }
            }
            d.pollFirst();
            
        }
        System.out.println(cnt);
    }
}