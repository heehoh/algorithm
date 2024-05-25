#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;

int check(vector<int> &v, int deps, int val) {
    for (int i = 0; i < deps; i++) {
        if (v[i] == val || abs(i - deps) == abs(v[i] - val))
            return 0;
    }
    return 1;
}


void DFS(vector<int> &v, int deps, int &num) {
    if (deps == N) {
        ++num;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (check(v, deps, i)) {
            v[deps] = i;
            DFS(v, deps + 1, num);
        }
    }
}

int main() {
    cin >> N;
    vector<int> v(N);
    int num = 0;
    for (int i = 0; i < N; i++) {
        v[0] = i;
        DFS(v, 1, num);
    }
    cout << num;
}