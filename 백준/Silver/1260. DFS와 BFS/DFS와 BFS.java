import java.util.*;

public class Main {
  static boolean[] visit;
  static ArrayList<Integer>[] graph;

  public static void bfs(int v) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(v);
    visit[v] = true;

    while (!queue.isEmpty()) {
      int temp = queue.poll();
      System.out.print(temp + " ");

      for (int nextV : graph[temp]) {
        if (!visit[nextV]) {
          queue.add(nextV);
          visit[nextV] = true;
        }
      }
    }
  }

  public static void dfs(int v) {
    visit[v] = true;
    System.out.print(v + " ");
    for (int nextV : graph[v]) {
      if (!visit[nextV]) dfs(nextV);
    }
  }

   public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt(); // 정점의 개수
    int m = sc.nextInt(); // 간선의 개수
    int v = sc.nextInt(); // 시작 위치

    visit = new boolean[n + 1];
    graph = new ArrayList[n + 1];
    for (int i = 1; i < n + 1; ++i) {
      graph[i] = new ArrayList<>();
    }
    while (m-- > 0) {
      int i = sc.nextInt();
      int j = sc.nextInt();
      graph[i].add(j);
      graph[j].add(i);
    }
    for (int i = 1; i < n + 1; ++i) {
        Collections.sort(graph[i]);
    }
    dfs(v);
    System.out.print("\n");
    Arrays.fill(visit, false);
    bfs(v);
    System.out.print("\n");
  }
}