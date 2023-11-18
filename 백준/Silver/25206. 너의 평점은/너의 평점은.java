import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double score = 0;
        int n = 0;
        double point = 0;
        String s;
        while((s = br.readLine()) != null) {
            String str[] = s.split(" ");
            ++n;
            double c = Double.parseDouble(str[1]);
            point += c;
            switch (str[2]) {
                case "A+":
                    score += c * 4.5;
                    break ;
                case "A0":
                    score += c * 4.0;
                    break ;
                case "B+":
                    score += c * 3.5;
                    break ;
                case "B0":
                    score += c * 3.0;
                    break ;
                case "C+":
                    score += c * 2.5;
                    break; 
                case "C0":
                    score += c * 2.0;
                    break ;
                case "D+":
                    score += c * 1.5;
                    break ;
                case "D0":
                    score += c * 1.0;
                    break ;
                case "F":
                    break; 
                default :
                    --n;
                    point -= c;
            }
        }
        System.out.println(score / n / (point / n));
    }
}