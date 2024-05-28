#include <iostream>

using namespace std;

int main() {
    string s; cin >> s;
    int one_num = 0;
    int one_flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1' && one_flag == 0) {
            ++one_num;
            one_flag = 1;
        }
        else if (s[i] == '0') {
            one_flag = 0;
        }
    }
    int zero_num = 0;
    int zero_flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0' && zero_flag == 0) {
            ++zero_num;
            zero_flag = 1;
        }
        else if (s[i] == '1') {
            zero_flag = 0;
        }
    }
    if (zero_num > one_num)
        cout << one_num;
    else
        cout << zero_num;
}