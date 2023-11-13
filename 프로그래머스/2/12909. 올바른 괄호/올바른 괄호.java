import java.util.Stack;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Integer> st = new Stack<>();
        for (int i=0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(')
                st.push(1);
            else {
                if (st.empty()) {
                    return false;
                }
                st.pop();
            }
        }
        if (!st.empty()) return false;
        return answer;
    }
}