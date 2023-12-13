import java.util.*;

public class Main {
    public static void sort(ArrayList<String> strs) {
        Collections.sort(strs, Comparator.comparing(String::length).thenComparing(Comparator.naturalOrder()));
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashSet<String> hash = new HashSet<>();
        
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; ++i)
            hash.add(sc.nextLine());
        ArrayList<String> strs = new ArrayList<>(hash);
        sort(strs);
        for (String str : strs) {
            System.out.println(str);
        }
    }
}