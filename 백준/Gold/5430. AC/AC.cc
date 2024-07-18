#include <iostream>
#include <vector>

using namespace std;

void cal(vector<int> &v, string &p) {
    int len = p.length();
    bool isReverse = false;
    int start = 0;
    int end = v.size();
    for (int i = 0; i < len; i++) {
        if (p[i] == 'D') {
            if (start == end) {
                cout << "error\n";
                return;
            }
            if (isReverse)
                --end;
            else
                ++start;
        } else {
            isReverse = !isReverse;
        }
    }
    if (start == end) {
        cout << "[]\n";
        return;
    }
    if (isReverse) {
        cout << "[";
        for (int i = end - 1; i > start; --i) {
            cout << v[i] << ",";
        }
        cout << v[start] << "]\n";
    } else {
        cout << "[";
        for (int i = start; i < end - 1; i++) {
            cout << v[i] << ",";
        }
        cout << v[end - 1] << "]\n";
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    
    while(T--) {
        string p; cin >> p;
        int len; cin >> len;
        char tmp; cin >> tmp;
        if (len == 0) {
            cin >> tmp;
        }
        vector<int> v(len);
        for (int i = 0; i < len; i++) {
            cin >> v[i];
            cin >> tmp;
        }
        cal(v, p);
    }
    
}