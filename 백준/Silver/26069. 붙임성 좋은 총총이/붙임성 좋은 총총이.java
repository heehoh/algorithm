import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashSet<String> set = new HashSet<>();
        
        set.add("ChongChong");
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String[] str = br.readLine().split(" ");
            if (set.contains(str[0])) {
                if (!set.contains(str[1]))
                    set.add(str[1]);
            }
            if (set.contains(str[1])) {
                if (!set.contains(str[0]))
                    set.add(str[0]);
            }
        }
        System.out.println(set.size());
    }
}