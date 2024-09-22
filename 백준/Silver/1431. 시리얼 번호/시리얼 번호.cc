#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string& a, string &b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= '0' && a[i] <= '9')
            sum1 += a[i] - '0';
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] >= '0' && b[i] <= '9')
            sum2 += b[i] - '0';
    }
    if (sum1 != sum2)
        return sum1 < sum2;
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), cmp);
    for (auto &a : s) {
        cout << a << '\n';
    }
}