import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String s = br.readLine();
        int[] array = new int[26];
        Arrays.fill(array, -1);
        int len = s.length();
        for (int i=0; i < len; ++i) {
            if (array[s.charAt(i) - 'a'] == -1)
                array[s.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i) {
            sb.append(array[i] + " ");
        }
        System.out.println(sb);
    }
}