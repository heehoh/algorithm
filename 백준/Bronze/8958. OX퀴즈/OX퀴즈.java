import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            int len = s.length();
            int sum = 0;
            int num = 0;
            for (int j=0; j < len; ++j) {
                if (s.charAt(j) == 'O') {
                    ++num;
                    sum += num;
                } else {
                    num = 0;
                }
            }
            sb.append(sum + "\n");
        }
        System.out.print(sb);
        br.close();
    }
}