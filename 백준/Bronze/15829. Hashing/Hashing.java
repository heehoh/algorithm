import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        int len = s.length();
        long hash = 0;
        for (int i=0; i < len; ++i) {
            char c = s.charAt(i);
            hash += (c - 'a' + 1) * Math.pow(31, i) % 1234567891l;
        }
        System.out.println(hash);
    }
}