#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;
int getTime(const string &s) {
    stringstream ss(s);
    int h, m;
    char c;
    ss >> h >> c >> m;
    return h * 60 + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string tmp;
    cin >> tmp;
    int S = getTime(tmp);
    cin >> tmp;
    int E = getTime(tmp);
    cin >> tmp;
    int Q = getTime(tmp);
    
    unordered_map<string, int> m;
    unordered_map<string, bool> check;
    int num = 0;
    while (!cin.eof()) {
        string s;
        cin >> s;
        int time = getTime(s);
        cin >> s;
        if (m.find(s) != m.end()) {
            if (time >= E && time <= Q) {
                if (check[s] == false) {
                    ++num;
                    check[s] = true;
                }
            }
        } else {
            if (time <= S) {
                m[s] = time;
            }
        }
    }
    cout << num;
}