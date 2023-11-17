import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder answer = new StringBuilder();
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(line, " \t");
            while (st.hasMoreTokens()) {
                String str = st.nextToken();
                if (str.equals("<br>")) {
                    addNewLine(answer, sb);
                    sb = new StringBuilder();
                } else if (str.equals("<hr>")) {
                    addNewLine2(answer, sb);
                    sb = new StringBuilder();
                } else if (sb.length() + str.length() > 80) {
                    addNewLine(answer, sb);
                    sb = new StringBuilder(str + " ");
                } else
                    sb.append(str + " ");
            }
        }
        if (sb.length() != 0)
            answer.append(sb.toString().trim());
        System.out.print(answer);
    }
    private static void addNewLine(StringBuilder answer, StringBuilder sb) {
        if (sb.length() != 0)
            answer.append(sb.toString().trim());
        answer.append("\n");
    }
    private static void addNewLine2(StringBuilder answer, StringBuilder sb) {
        if (sb.length() != 0) {
            answer.append(sb.toString().trim() + "\n");
        }
        for (int i = 0; i < 80; i++) {
            answer.append("-");
        }
        answer.append("\n");
    }
}