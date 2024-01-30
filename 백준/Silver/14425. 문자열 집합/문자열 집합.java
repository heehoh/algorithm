import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] strs = br.readLine().split(" ");
        int n = Integer.parseInt(strs[0]);
        int m = Integer.parseInt(strs[1]);
        HashSet<String> set = new HashSet<>();
        while (n-- > 0) {
            set.add(br.readLine());
        }
        int cnt = 0;
        while (m-- > 0) {
            if (set.contains(br.readLine())) {
                ++cnt;
            }
        }
        System.out.println(cnt);
    }
}