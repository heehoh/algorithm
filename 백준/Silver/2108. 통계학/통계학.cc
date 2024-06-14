#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<int, int> m;

int N;

int mod() {
    vector<int> v;
    int max = 0;
    for(const auto & x: m) {
        if (max < x.second) {
            max = x.second;
            v.clear();
            v.push_back(x.first);
        } else if (max == x.second) {
            v.push_back(x.first);
        }
    }
    sort(v.begin(), v.end());
    if (v.size() == 1)
        return v[0];
    return v[1];
}

int main() {
    cin >> N;
    vector<int> v(N);
    double sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
        m[v[i]]++;
    }
    sum = sum / N;
    int av;
    if (sum > 0)
        av = sum + 0.5;
    else
        av = sum - 0.5;
    sort(v.begin(), v.end());
    cout << av << '\n' << v[N/2] << '\n' << mod() << '\n' << v[N-1] - v[0];
}