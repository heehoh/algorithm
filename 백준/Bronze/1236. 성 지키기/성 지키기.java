import java.util.*;

public class Main { 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int r = sc.nextInt();
        int c = sc.nextInt();
        
        sc.nextLine();
        boolean[] row = new boolean[r];
        boolean[] col = new boolean[c];
        for (int i = 0; i < r; ++i) {
            String s = sc.nextLine();
            for (int j = 0; j < c; ++j) {
                if (s.charAt(j) == 'X') {
                    col[j] = true;
                    row[i] = true;
                }
            }
        }
        int cntR = 0;
        int cntC = 0;
        for (int i = 0; i < r; ++i) {
            if (row[i] == false)
                ++cntR;
        }
        for (int i = 0; i < c; ++i) {
            if (col[i] == false)
                ++cntC;
        }
        if (cntR > cntC) {
            System.out.println(cntR);
        } else {
            System.out.println(cntC);
        }
    }
}