import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            HashMap<String, Integer> map = new HashMap<>();
            String[] str = br.readLine().split(" ");
            int max = 1;
            String s = "s";
            for (int i = 1; i < str.length; ++i) {
                if (map.containsKey(str[i])) {
                    int num = map.get(str[i]) + 1;
                    map.put(str[i], num);
                    if (max < num) {
                        max = num;
                        s = str[i];
                    }
                } else {
                    map.put(str[i], 1);
                }
            }
            if (max <= (str.length - 1) / 2) {
                sb.append("SYJKGW\n");
            } else {
                sb.append(s).append('\n');
            }
        }
        System.out.print(sb);
    }
}