import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int channel = sc.nextInt();
        int num = sc.nextInt();
        boolean[] out = new boolean[10];
        for (int i = 0; i < num; i++) {
            out[sc.nextInt()] = true;
        }
        int value = Math.abs(channel - 100);
        if (value == 0) {
            System.out.println(0);
            return;
        }
        for (int i = 0; i <= 999999; ++i) {
            String str = String.valueOf(i);
            int len = str.length();
            
            boolean isOutof = false;
            for(int j = 0; j < len; ++j) {
                if (out[str.charAt(j) - '0']) {
                    isOutof = true;
                    break;
                }
            }
            if (isOutof == false) {
                int min = Math.abs(channel - i) + len;
                value = Math.min(min, value);
            }
        }
        System.out.println(value);
    }
}