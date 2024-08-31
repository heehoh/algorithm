#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, maxH;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    vector<int> tree(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());

    long long low = 0;
    long long high = tree[N-1];
    
    while (low <= high) {
        long long sum = 0;
        long long cut = (low + high) / 2;
        for (int i = 0; i < N; i++) {
            if (tree[i] - cut > 0) sum += tree[i] - cut;
        }

        if (sum >= M) {
            maxH = cut;
            low = cut + 1;
        } else {
            high = cut - 1;
        }
    }
    cout << maxH;
    
}