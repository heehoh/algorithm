#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> v;

void recur(int st, int en) {
    if (st >= en) return;
    if (st == en-1) {
        cout << v[st] << '\n';
        return;
    }
    int idx = st + 1;
    while (idx< en) {
        if (v[st] < v[idx]) break;
        idx++;
    }
    recur(st+1, idx);
    recur(idx, en);
    cout << v[st] << '\n';
    return;
}

int main() {
    while(cin >> n) {
        v.push_back(n);
    }
    
    recur(0, v.size());
}