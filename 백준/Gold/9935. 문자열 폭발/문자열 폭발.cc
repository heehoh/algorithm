#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
string s, boom;

void check(stack<char> &st, string &boom) {
    int len = boom.length();
    string str;
    str.reserve(len);
    if (st.size() >= len) {
        for (int i = 0; i < len; i++) {
            str.push_back(st.top()); st.pop();
        }
        reverse(str.begin(), str.end());
        if (str != boom) {
            for (auto c : str) {
                st.push(c);
            }
        }
    }
}

int main() {
    cin >> s >> boom;
    stack<char> st;
    
    for (auto c : s) {
        st.push(c);
        if (c == boom[boom.length() - 1]) {
            check(st, boom);
        }
    }
    int len = st.size();
    string str;
    str.reserve(len);
    for (int i = 0; i < len; i++) {
        str.push_back(st.top()); st.pop();
    }
    reverse(str.begin(), str.end());
    if (str == "")
        cout << "FRULA";
    else
        cout << str;
}