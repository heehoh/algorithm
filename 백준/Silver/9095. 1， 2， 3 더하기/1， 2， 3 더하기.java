import java.util.*;

public class Main {
  static int[] d = new int[11];
  public static void main(String[] args) {
    d[0] = 1;
    d[1] = 2;
    d[2] = 4;
    d[3] = 7;
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for (int i = 0; i < t; i++) {
      int n = sc.nextInt();
      System.out.println(dp(n -1));
    }
  }
  public static int dp(int n) {
    if (d[n] == 0)
      d[n] = dp(n-1) + dp(n-2) + dp(n-3);
    return d[n];
  }
}