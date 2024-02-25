import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int M = Integer.parseInt(str[1]);
        int[] A = new int[N];
        str = br.readLine().split(" ");
        for (int i = 0; i < N; ++i) {
            A[i] = Integer.parseInt(str[i]);
        }
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            int target = M - A[i];
            if (target == 0) {
                ++cnt;
                continue;
            }
            if (target < 0)
                continue;
            for (int j = i + 1; j < N; ++j) {
                target -= A[j];
                if (target == 0) {
                    ++cnt;
                    break;
                } else if (target < 0) {
                    break;
                }
            }
        }
        System.out.println(cnt);
    }
}