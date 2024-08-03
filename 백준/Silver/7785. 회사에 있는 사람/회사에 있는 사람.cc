#include <iostream>
#include <set>
using namespace std;
int main() {
    int n; cin >> n;
    set<string, greater<>> s;
    while (n--) {
        string s1, s2; cin >> s1 >> s2;
        if (s2 == "enter") {
            s.insert(s1);
        } else {
            s.erase(s1);
        }
    }
    for (auto &a : s) {
        cout << a << "\n";
    }
}