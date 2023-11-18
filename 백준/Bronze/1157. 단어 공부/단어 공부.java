import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int[] alph = new int[26];
        int len = s.length();
        for (int i=0; i < len; ++i) {
            char c = s.charAt(i);
            if (c <= 'Z')
                alph[c - 'A'] += 1;
            else
                alph[c - 'a'] += 1;
        }
        int max = 0;
        for (int i = 0; i < 26; ++i) {
            if (max < alph[i])
                max = alph[i];
        }
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (max == alph[i])
                ++count;
            if (count == 2) {
                System.out.println("?");
                return ;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (max == alph[i])
                System.out.println((char)((char)i + 'A'));
        }
    }
}