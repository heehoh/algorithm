#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> v(N);
    for (auto &a : v) {
        cin >> a;
    }
    int left = 0;
    int right = N - 1;
    int res = abs(v[left] + v[right]);
    int resA = v[left];
    int resB = v[right];
    
    while (left < right) {
        int tmp = v[left] + v[right];
        if (abs(tmp) < res) {
            res = abs(tmp);
            resA = v[left];
            resB = v[right];
        }
        if (tmp < 0)
            ++left;
        else
            --right;
    }
    cout << resA << " " << resB << "\n";
}