import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        Map<String,String> idMap = new HashMap<>();
        for (String cmd : record) {
            String[] tmp = cmd.split(" ");
            if(tmp[0].equals("Enter") || tmp[0].equals("Change")) {
                idMap.put(tmp[1], tmp[2]);
            }
        }
        List<String> answer = new ArrayList<>();
        for (String cmd : record) {
            String tmp[] = cmd.split(" ");
            switch (tmp[0]) {
                case "Enter" :
                    answer.add(idMap.get(tmp[1]) + "님이 들어왔습니다.");
                    break ;
                case "Leave" :
                    answer.add(idMap.get(tmp[1]) + "님이 나갔습니다.");
                    break ;
                default:
                    break ;
            }
            
        }
        return answer.stream().toArray(array -> new String[answer.size()]);
    }
}