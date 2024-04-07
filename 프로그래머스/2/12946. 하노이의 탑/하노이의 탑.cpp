#include <string>
#include <vector>

using namespace std;

void move(vector<vector<int>> &v, int from, int to) {
    v.push_back({from, to});
}

void hanoi(vector<vector<int>> &v, int from, int by, int to, int n) {
    if (n == 0)
        return ;
    hanoi(v, from, to, by, n -1);
    move(v, from, to);
    hanoi(v, by, from, to, n - 1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, 1, 2, 3, n);
    return answer;
}