#include <iostream>
#include <list>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        list<char> l;
        auto it = l.begin();
        for (auto c : s) {
            if (c == '<') {
                if (it != l.begin())
                    --it;
            } else if (c == '>') {
                if (it != l.end()) {
                    ++it;
                }
            } else if (c == '-') {
                if (it == l.begin())
                    continue;
                --it;
                it = l.erase(it);
            } else {
                it = l.insert(it, c);
                ++it;
            }
        }
        for (auto c : l) {
            cout << c;
        }
        cout << '\n';
    } 
}