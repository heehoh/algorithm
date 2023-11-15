import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();
        int n = sc.nextInt();
        StringBuilder answer = new StringBuilder();
        int watch = 0;
        for (int i = 0; i < n; ++i) {
            int val = sc.nextInt();
            while (watch < val) {
                ++watch;
                stack.push(watch);
                answer.append("+\n");
            }
            if (!stack.empty() && val == stack.peek()) {
                stack.pop();
                answer.append("-\n");
            } else {
                System.out.println("NO");
                return ;
            }
        }
        if (stack.empty())
            System.out.print(answer);
        else
            System.out.println("NO");
        sc.close();
    }
}