import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((o1, o2) -> o2 - o1);
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            if (minHeap.size() == maxHeap.size())
                maxHeap.add(sc.nextInt());
            else
                minHeap.add(sc.nextInt());
            if (!minHeap.isEmpty()) {
                if (minHeap.peek() < maxHeap.peek()) {
                    int tmp = minHeap.poll();
                    minHeap.add(maxHeap.poll());
                    maxHeap.add(tmp);
                }
            }
            sb.append(maxHeap.peek()).append('\n');
        }
        System.out.println(sb);
    }
}