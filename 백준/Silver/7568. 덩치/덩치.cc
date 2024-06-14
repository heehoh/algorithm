#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int N;
vector<pair<int, int>> v;

int main() {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].X >> v[i].Y;
    }
    int rank = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i].X < v[j].X && v[i].Y < v[j].Y) {
                ++rank;
            }
        }
        cout << rank << ' ';
        rank = 1;
    }
    
}