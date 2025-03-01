#include <string>
#include <vector>

using namespace std;

bool check(int startday, int time, vector<int> &logs) {
    time = (time / 100) * 60 + time % 100;
    for (int i = 0; i < logs.size(); i++)
    {
        int log = (logs[i] / 100) * 60 + logs[i] % 100;
        int day = (i + startday) % 7;
        if (day == 6 || day == 0)
            continue;
        if (log - time > 10) {
            return true;
        }
    }
    return false;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++) {
        if (check(startday, schedules[i], timelogs[i]))
            continue;
        ++answer;
    }
    return answer;
}