#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visited[100001];

struct Val {
    int num;
    string s;
};

int left(int num) {
    int a = num / 1000;
    int b = num % 1000;
    b *= 10;
    return b + a;
}

int right(int num) {
    int a = num % 10;
    int b = num / 10;
    return a * 1000 + b;
}

void cal(int A, int B) {
    queue<Val> q;
    q.push({A, ""});
    visited[A] = true;
    
    while (!q.empty()) {
        Val v = q.front(); q.pop();
        if (v.num == B) {
            cout << v.s << "\n";
            return ;
        }
        int D = v.num * 2 % 10000;
        if (!visited[D]) {
            q.push({D, v.s + "D"});
            visited[D] = true;
        }
        int S = (v.num == 0) ? 9999 : v.num - 1; 
        if (!visited[S]) {
            q.push({S, v.s + "S"});
            visited[S] = true;
        }
        int L = left(v.num);
        if (!visited[L]) {
            q.push({L, v.s + "L"});
            visited[L] = true;
        }
        int R = right(v.num);
        if (!visited[R]) {
            q.push({R, v.s + "R"});
            visited[R] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        memset(visited, false, sizeof(visited));
        int A, B; cin >> A >> B;
        cal(A, B);
    }
}