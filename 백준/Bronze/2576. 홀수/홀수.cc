#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sum = 0;
    int min = 1e9;
    for (int i = 0; i < 7; i++) {
        int num; cin >> num;
        if (num % 2 == 1) {
            sum += num;
            if (min > num)
                min = num;
        }
    }
    if (sum != 0) {
        cout << sum << "\n" << min;
    } else {
        cout << -1;
    }
}