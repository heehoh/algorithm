#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
void recur(vector<char> &v, vector<char> &comb, int dep, int st) {
    if (dep == n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (comb[i] == 'i' || comb[i] == 'a' || comb[i] == 'e' || comb[i] == 'o' || comb[i] == 'u')
                ++count;
        }
        if (count == 0 || n - count < 2)
            return ;
        for (int i = 0; i < n; i++) {
            cout << comb[i];
        }
        cout << "\n";
        return;
    }
    for (int i = st; i < m; i++) {
        comb[dep] = v[i];
        recur(v, comb, dep+1, i+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<char> v(m);
    vector<char> comb(n);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    recur(v, comb, 0, 0);
}