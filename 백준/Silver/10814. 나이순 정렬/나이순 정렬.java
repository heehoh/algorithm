import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[][] arr = new String[n][2];
        for (int i = 0; i < n; ++i) {
            String[] str = br.readLine().split(" ");
            arr[i][0] = str[0];
            arr[i][1] = str[1];
        }
        Arrays.sort(arr, new Comparator<String[]>() {
            @Override
            public int compare(String[] o1, String[] o2) {
                return Integer.parseInt(o1[0]) - Integer.parseInt(o2[0]);
            }
        });
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            sb.append(arr[i][0]).append(" ").append(arr[i][1]).append("\n");
        }
        System.out.print(sb);
    }
}