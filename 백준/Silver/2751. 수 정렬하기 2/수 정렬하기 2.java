import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            arr.add(sc.nextInt());
        }
        Collections.sort(arr);
        StringBuilder sb = new StringBuilder();
        for (int i : arr) {
            sb.append(i).append('\n');
        }
        System.out.print(sb);
    }
}