import java.io.*;
import java.util.*;

class Time {
    int begin;
    int end;
    public Time(int b, int e) {
        this.begin = b;
        this.end = e;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        int n = Integer.parseInt(input);
        Time[] times = new Time[n];
        for (int i = 0; i < n; ++i) {
            String[] inputs = br.readLine().split(" ");
            times[i] = new Time(Integer.parseInt(inputs[0]), Integer.parseInt(inputs[1]));
        }
        Arrays.sort(times, (o1, o2) -> {
            if (o1.end != o2.end) {
                return o1.end - o2.end; // 끝나는 시간으로 정렬
            } else {
                return o1.begin - o2.begin; // 끝나는 시간이 같으면 시작 시간으로 정렬
            }
        });
        int end = 0; // 회의 종료 시간
        int val = 0;
        for (int i = 0; i < n; ++i) {
            if (times[i].begin >= end) {
                ++val;
                end = times[i].end;
            }
        }
        System.out.println(val);
    }
}