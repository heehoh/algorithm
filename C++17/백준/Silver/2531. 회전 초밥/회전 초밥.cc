#include <iostream>
#include <vector>

using namespace std;

int N, d, k, c;

int main() {
    cin >> N >> d >> k >> c;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        int eat = 0;
        vector<bool> check(d+1, false); 
        check[c] = true;
        ++eat;
        for (int j = i; j < i + k; j++) {
            int susi = v[j % N];
            if (!check[susi]) {
                check[susi] = true;
                ++eat;
            }
        }
        if (eat > max)
            max = eat;
    }
    cout << max;
}