import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int N = Integer.parseInt(str[0]);
        int K = Integer.parseInt(str[1]);
        
        str = br.readLine().split(" ");
        int[] score = new int[N];
        int low = 0, high = 0;
        for (int i = 0; i < N; ++i) {
            score[i] = Integer.parseInt(str[i]);
            high += score[i];
        }
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = 0, cnt = 0;
            for (int i = 0; i < N; ++i) {
                sum += score[i];
                if (sum >= mid) {
                    ++cnt;
                    sum = 0;
                }
            }
            if (cnt >= K) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        System.out.println(high);
    }
}