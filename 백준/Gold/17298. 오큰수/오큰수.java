import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Stack<Integer> stack = new Stack<>();
        int[] a = new int[n];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n; ++i) {
            while (!stack.isEmpty() && a[stack.peek()] < a[i]) {
                a[stack.pop()] = a[i];
            }
            stack.push(i);
        }
        while(!stack.isEmpty()) {
            a[stack.pop()] = -1;
        }
        for (int i = 0; i < n; ++i) {
            sb.append(a[i]).append(" ");
        }
        System.out.println(sb);
    }
}