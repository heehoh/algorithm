import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for (int i=0; i < n; ++i) {
            String s = sc.nextLine();
            String[] word = s.split(" ");
            StringBuilder newString = new StringBuilder();
            for (int j = 0; j < word.length; ++j) {
                StringBuilder reversed = new StringBuilder(word[j]).reverse();
                newString.append(reversed.toString() + " ");
            }
            System.out.println(newString.toString());
        }
    }
}