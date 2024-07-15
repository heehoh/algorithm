#include <iostream>
#include <vector>

using namespace std;
int N;
int sign[4];
vector<int> vals;
vector<int> signs;

int min() {
    int min = 2147483647;
    for (auto val : vals) {
        if (min > val)
            min = val;
    }
    return min;
}

int max() {
    int max = -2147483647;
    for (auto val : vals) {
        if (max < val)
            max = val;
    }
    return max;
}

int sum(vector<int> &v) {
    int sum = v[0];
    for (int i = 0; i < N - 1; i++) {
        if (signs[i] == 0) {
            sum += v[i+1];
        } else if (signs[i] == 1) {
            sum -= v[i+1];
        } else if (signs[i] == 2) {
            sum *= v[i+1];
        } else {
            sum /= v[i+1];
        }
    }
    return sum;
}

void perm(vector<int> &v, int sign_num) {
    if (sign_num == 0) {
        vals.push_back(sum(v));
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (sign[i] > 0) {
            --sign[i];
            signs.push_back(i);
            perm(v, sign_num - 1);
            signs.pop_back();
            ++sign[i];
        }
    }
}

int main() {
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < 4; i++)
        cin >> sign[i];
    perm(v, N - 1);
    cout << max() << '\n' << min();
}