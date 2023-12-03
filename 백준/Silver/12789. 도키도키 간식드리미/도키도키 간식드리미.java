import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();
        int n = sc.nextInt();
        int[] line = new int[n];
        
        for (int i = 0; i < n; ++i) {
            line[i] = sc.nextInt();
        }
        
        int cnt = 1;
        for (int i = 0; i < n; ++i) {
            if (cnt == line[i])
                ++cnt;
            else {
                if (!stack.empty() && cnt == stack.peek()) {
                    stack.pop();
                    ++cnt;
                    --i;
                } else
                    stack.push(line[i]);
            }
        }
        while (!stack.empty() && cnt == stack.peek()) {
            stack.pop();
            ++cnt;
        }
        if (stack.empty())
            System.out.println("Nice");
        else
            System.out.println("Sad");
    }
}