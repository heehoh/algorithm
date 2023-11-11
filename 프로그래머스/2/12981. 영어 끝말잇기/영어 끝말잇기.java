class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        int min = 101;
        for (int i=0; i < words.length - 1; i++) {
            String str1 = words[i];
            String str2 = words[i+1];
            if (str1.charAt(str1.length() - 1) != str2.charAt(0)) {
                answer[0] = (i+1) % n + 1;
                answer[1] = (i+1) / n + 1;
                min = i + 1;
                break ;
            }
        }
        for (int i=0; i < words.length - 1; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (words[i].equals(words[j])) {
                    if (min > j) {
                        answer[0] = j % n + 1;
                        answer[1] = j / n + 1;
                    }
                }
            }
        }
        return answer;
    }
}