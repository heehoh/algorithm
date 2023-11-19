import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        int s = 0;
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            if(str.equals("all"))
                s = (~0);
            else if (str.equals("empty"))
                s = 0;
            else {
                int num = Integer.parseInt(st.nextToken());
                if(str.equals("add"))
                    s |= (1 << (num-1));
                else if(str.equals("remove"))
                    s &= ~(1 << (num-1));
                else if(str.equals("check"))
                    sb.append((s & (1 << (num-1))) != 0 ? "1\n" : "0\n");
                else
                    s ^= (1 << (num-1));
            }
        }
        System.out.print(sb);
    }
}