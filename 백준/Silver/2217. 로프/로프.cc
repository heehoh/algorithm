#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> vec(N);
    
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int max = 0;
    for (int i = 0; i < N; ++i) {
        int tmp = vec[i] * (N - i);
        if (tmp > max)
            max = tmp;
    }
    cout << max;
}