class Solution {
    public int solution(int[] cards) {
        int len = cards.length;
        
        int box1 = 0;
        int box2 = 0;
        for (int i = 0; i < len; ++i) {
            if (cards[i] == 0)
                continue ;
            int checkBox = openBox(cards, i);
            if (box1 < checkBox) {
                box2 = box1;
                box1 = checkBox;
            } else if (box2 < checkBox) {
                box2 = checkBox;
            }
        }
        return box1 * box2;
    }
    private int openBox(int[] cards, int i) {
        if (cards[i] == 0)
            return 0;
        int idx = cards[i] - 1;
        cards[i] = 0;
        return openBox(cards, idx) + 1;
    }
}