#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;

void DFS(vector<int> &v, int deps, int &num) {
    if (deps == N) {
        ++num;
        return;
    }
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (; j < deps; j++) {
            if (v[j] == i || abs(v[j] - i) == abs(j - deps)) {
                break;
            }
        }
        if (j == deps) {
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