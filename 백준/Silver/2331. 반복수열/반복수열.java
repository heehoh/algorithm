import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int p = sc.nextInt();
        
        LinkedList<Integer> list = new LinkedList<>();
        list.add(a);
        
        while (true) {
            int tmp = 0;
            int num = list.peekLast();
            while (num != 0) {
                tmp += Math.pow(num % 10, p);
                num /= 10;
            }
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i) == tmp) {
                    System.out.println(i);
                    return ;
                }
            }
            list.add(tmp);
        }
    }
}