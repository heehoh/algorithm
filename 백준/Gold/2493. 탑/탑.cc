#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;

    stack<pair<int, int>> s;
    int height;

    for (int i = 0; i < N; i++) {
        cin >> height;

        while (!s.empty()) {
            if (height < s.top().second) {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        if (s.empty()) {
            cout << "0 ";
        }
        s.push({i+1, height});
    }
    
}