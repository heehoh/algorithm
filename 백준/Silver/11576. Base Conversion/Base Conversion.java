import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int n = sc.nextInt();
        int num = 0;
        while (n-- > 0) {
            int k = sc.nextInt();
            num = num * a + k;
        }
        StringBuilder sb = new StringBuilder();
        ArrayList<Integer> arr = new ArrayList<>();
        while (num != 0) {
            arr.add(num % b);
            num /= b;
        }
        for (int i = arr.size() - 1; i >= 0; --i) {
            sb.append(arr.get(i)).append(' ');
        }
        System.out.println(sb);
    }
}