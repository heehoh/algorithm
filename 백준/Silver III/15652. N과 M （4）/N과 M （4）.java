import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static StringBuilder sb = new StringBuilder();
    static int[] arr;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] strs = br.readLine().split(" ");
        N = Integer.parseInt(strs[0]);
        M = Integer.parseInt(strs[1]);
        
        arr = new int[M];
        dfs(0, 0);
        System.out.println(sb);
    }
    static void dfs(int dep, int start) {
        if (dep == M) {
            for (int v : arr) {
                sb.append(v).append(" ");
            }
            sb.append("\n");
            return;
        }
        
        for (int i = start; i < N; ++i) {
            arr[dep] = i+1;
            dfs(dep+1, i);
        }
    }
}