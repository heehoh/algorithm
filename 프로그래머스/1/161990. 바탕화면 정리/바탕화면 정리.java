class Solution {
    public int[] solution(String[] wallpaper) {
        int col = wallpaper.length;
        int row = wallpaper[0].length();
        int[] answer = {col, row, -1, -1};
        for (int i=0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                char c = wallpaper[i].charAt(j);
                if (c == '#') {
                    if (answer[0] > i)
                        answer[0] = i;
                    if (answer[1] > j)
                        answer[1] = j;
                    if (answer[2] < i + 1)
                        answer[2] = i + 1;
                    if (answer[3] < j + 1)
                        answer[3] = j + 1;
                }
            }
        }
        return answer;
    }
}