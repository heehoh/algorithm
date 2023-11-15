import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder answer = new StringBuilder();
        for (int i=0; i<n; i++) {
            String s = br.readLine();
            int l = s.length();
            int count = 0;
            for (int j = 0; j < l; ++j) {
                if (s.charAt(j) == '(')
                    ++count;
                else {
                    if (count == 0) {
                        --count;
                        break ;
                    } else {
                        --count;
                    }
                }
            }
            if (count == 0)
                answer.append("YES\n");
            else
                answer.append("NO\n");
        }
        System.out.print(answer);
    }
}