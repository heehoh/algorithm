#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x1, y1, r1, x2, y2, r2;
    double d;
    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        int bigR, smallR;
        bigR = r1 > r2 ? r1 : r2;
        smallR = r1 < r2 ? r1 : r2;
        if (d == 0 && bigR == smallR)
            cout << "-1\n";
        else if (d > bigR + smallR || bigR > smallR + d)
            cout << "0\n";
        else if (d == bigR + smallR || bigR == smallR + d)
            cout << "1\n";
        else
            cout << "2\n";
    }
}