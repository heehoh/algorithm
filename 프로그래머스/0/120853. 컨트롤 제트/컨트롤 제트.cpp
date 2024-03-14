#include <string>
#include <vector>

using namespace std;

int getNum(const string &s, int &idx) {
    int num = 0;
    int flag = 1;
    if (s[idx] == '-') {
        flag = -1;
        ++idx;
    }
    while (s[idx] && s[idx] != ' ') {
        num *= 10;
        num += s[idx] - '0';
        ++idx;
    }
    return num * flag;
}

int solution(string s) {
    int idx = 0;
    int sum = 0;
    int num = 0;
    int len = s.length();
    while (idx < len) {
        if (s[idx] == ' ')
            ++idx;
        else if (s[idx] == 'Z') {
            sum -= num;
            ++idx;
        } else {
            num = getNum(s, idx);
            sum += num;
        }
    }
    return sum;
}