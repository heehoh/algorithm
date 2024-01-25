import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            TreeMap<Integer, Integer> map = new TreeMap<>();
            while (N-- > 0) {
                String[] s = br.readLine().split(" ");
                if (s[0].equals("I")) {
                    int n = Integer.parseInt(s[1]);
                    if (map.containsKey(n)) {
                        map.put(n, map.get(n) + 1);
                    } else {
                        map.put(n , 1);
                    }
                }
                else {
                    if (map.isEmpty())
                        continue ;
                    int n = Integer.parseInt(s[1]);
                    if (n == 1) {
                        int max = map.lastKey();
                        if (map.get(max) == 1) {
                            map.remove(max);
                        } else {
                            map.put(max, map.get(max) - 1);
                        }
                    }
                    else {
                        int min = map.firstKey();
                        if (map.get(min) == 1) {
                            map.remove(min);
                        } else {
                            map.put(min, map.get(min) - 1);
                        }
                    }
                }
            }
            if (map.isEmpty()) {
                sb.append("EMPTY\n");
            } else {
                sb.append(map.lastKey()).append(' ').append(map.firstKey()).append('\n');
            }
        }
        System.out.print(sb);
    }
}