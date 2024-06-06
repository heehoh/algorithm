#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool check[10001] = {false, };

void printArr(vector<int> &answer) {
    for (auto v : answer) {
        cout << v << ' ';
    }
    cout << '\n';
}

void permutation(vector<int> &vec, vector<int> &answer, vector<bool> &check, int dep) {
    if (dep == M) {
        printArr(answer);
        return ;
    }
    for (int i = 0; i < N; i++) {
        if (!check[i]) {
            answer[dep] = vec[i];
            check[i] = true;
            permutation(vec, answer, check, dep+1);
            check[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    vector<int> vec(N);
    vector<bool> check(N);
    vector<int> answer(M);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    permutation(vec, answer, check, 0);
}