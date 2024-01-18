import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nums = br.readLine().split(" ");
        int n = Integer.parseInt(nums[0]);
        int m = Integer.parseInt(nums[1]);
        
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            set.add(br.readLine());
        }
        ArrayList<String> names = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            String name = br.readLine();
            if (set.contains(name)) {
                names.add(name);
            }
        }
        Collections.sort(names);
        
        StringBuilder sb = new StringBuilder();
        sb.append(names.size()).append('\n');
        for (String name : names) {
            sb.append(name).append('\n');
        }
        System.out.print(sb);
    }
}