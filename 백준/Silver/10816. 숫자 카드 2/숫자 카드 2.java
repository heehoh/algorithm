import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<Integer, Integer> hash = new HashMap<>();
        while (n-- > 0) {
            int a = Integer.parseInt(st.nextToken());
            if (hash.containsKey(a)) {
                int num = hash.get(a);
                hash.put(a, ++num);
            }
            else {
                hash.put(a, 1);
            }
        }
        n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        while (n-- > 0) {
            int a = Integer.parseInt(st.nextToken());
            if (hash.containsKey(a)) {
                sb.append(hash.get(a)).append(' ');
            } else
                sb.append("0 ");
        }
        System.out.println(sb);
    }
}