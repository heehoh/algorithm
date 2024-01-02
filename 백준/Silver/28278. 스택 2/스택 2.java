import java.util.*;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        while (n-- > 0) {
            int a = sc.nextInt();
            if (a == 1) {
                stack.push(sc.nextInt());
            }
            else if (a == 2) {
                if (!stack.isEmpty())
                    sb.append(stack.pop()).append('\n');
                else 
                    sb.append(-1).append('\n');
            } else if (a == 3) {
                sb.append(stack.size()).append('\n');
            } else if (a == 4) {
                sb.append(stack.isEmpty() ? 1 : 0).append('\n');
            } else {
                if (stack.isEmpty())
                    sb.append(-1).append('\n');
                else
                    sb.append(stack.peek()).append('\n');
            }
        }
        System.out.println(sb);
    }
}