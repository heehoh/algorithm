import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        double[] a = new double[n];
        for (int i = 0; i < n; ++i) {
            a[i] = (double)sc.nextInt();
        }
        int len = s.length();
        Stack<Double> stack = new Stack();
        for (int i = 0; i < len; ++i) {
            char c = s.charAt(i);
            if (c <= 'Z' && c >= 'A')
                stack.push(a[c - 'A']);
            else {
                double x = stack.pop();
                double y = stack.pop();
                if (c == '+')
                    stack.push(y+x);
                else if (c == '-')
                    stack.push(y-x);
                else if (c == '*')
                    stack.push(y*x);
                else
                    stack.push(y/x);
            }
        }
        System.out.printf("%.2f", stack.pop());
    }
}