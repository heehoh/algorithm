#include <iostream>
#include <unordered_map>

using namespace std;
const long long MOD = 1000000007;
unordered_map<long long, long long> map;


long long dp(long long a) {
    if (map[a]) {
        return map[a];
    }
    if (a % 2 == 0) {
        map[a] = dp(a/2) * (dp(a/2 + 1) + dp(a/2 - 1)) % MOD;
    } else { 
        map[a] = (dp((a+1)/2) * dp((a+1)/2) + dp((a-1)/2) * dp((a-1)/2)) % MOD;
    }
    return map[a];
}

int main() {
    long long a; cin >> a;
    map[0] = 0;
    map[1] = 1;
    map[2] = 1;
    cout << dp(a);
}