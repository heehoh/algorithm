#include <string>
#include <vector>

using namespace std;

int contain(const string &s, const string &c) {
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] == c[0])
            return 1;
    }
    return 0;
}

int solution(vector<string> spell, vector<string> dic) {
    int dicLen = dic.size();
    int spellLen = spell.size();
    for (int i = 0; i < dicLen; ++i) {
        int j = 0;
        for(; j < spellLen; ++j) {
            if (contain(dic[i], spell[j]))
                continue;
            break;
        }
        if (j == spellLen)
            return 1;
    }
    return 2;
}