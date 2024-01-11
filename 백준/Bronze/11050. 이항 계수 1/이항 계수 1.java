import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int r = Integer.parseInt(str[1]);
        System.out.println(bc(n, r));
        
    }
    static int bc(int n, int r) {
        if (n == r || r == 0)
            return 1;
        return bc(n - 1, r - 1) + bc(n - 1, r);
    }
}