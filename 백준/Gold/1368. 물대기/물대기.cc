#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct Edge { 
    int x, y, cost; 
};

bool cmp(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

vector<int> p(301, -1);

int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int isDiff(int v1, int v2) {
    v1 = find(v1); 
    v2 = find(v2);
    if (v1 == v2) {
        return 0;
    }
    if (p[v1] == p[v2]) {
        --p[v1];
    }
    if (p[v1] < p[v2]) {
        p[v2] = v1;
    } else {
        p[v1] = v2;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<Edge> edge;
    int cost;

    for (int i = 1; i <= n; i++) {
        cin >> cost;
        edge.push_back({i, 0, cost});
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost;
            if (i > j) {
                edge.push_back({i, j, cost});
            }
        }
    }

    sort(edge.begin(), edge.end(), cmp);

    int total = 0;
    int num = 0;

    for (const auto& e : edge) {
        if (isDiff(e.x, e.y)) {
            total += e.cost;
            ++num;
        }
        if (num == n) {
            break;
        }
    }

    cout << total << '\n';

    return 0;
}