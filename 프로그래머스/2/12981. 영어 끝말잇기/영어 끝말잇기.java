import java.util.HashSet;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        HashSet<String> set = new HashSet<String>();
        
        set.add(words[0]);
        for (int i=0; i < words.length - 1; i++) {
            String str1 = words[i];
            String str2 = words[i+1];
            set.add(str2);
            if (set.size() == i + 1 || 
                str1.charAt(str1.length() - 1) != str2.charAt(0)) {
                answer[0] = (i+1) % n + 1;
                answer[1] = (i+1) / n + 1;
                break;
            }
        }
        return answer;
    }
}