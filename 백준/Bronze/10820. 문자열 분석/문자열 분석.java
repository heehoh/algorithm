import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        while (sc.hasNextLine()) {
            String s = sc.nextLine();
            int low=0, up=0, num=0, space=0;
            int len = s.length();
            for (int i = 0; i < len; ++i) {
                char c = s.charAt(i);
                if (c >='a' && c <='z')
                    ++low;
                else if (c == ' ')
                    ++space;
                else if (c >= 'A' && c <= 'Z')
                    ++up;
                else
                    ++num;
            }
            sb.append(low).append(" ").append(up).append(" ")
                .append(num).append(" ").append(space).append("\n");
        }
        System.out.print(sb);
    }
}