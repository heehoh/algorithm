#include <iostream>

using namespace std;

long long N;
long long tsize[6];
long long T, P;

void checkP(long long &set, long long &num) {
    set = N / P;
    num = N - set * P;
}

long long checkT() {
    long long num = 0;
    for (int i = 0; i < 6; i++) {
        if (tsize[i] % T != 0)
            ++num;
        num += tsize[i] / T;
    }
    return num;
}

int main() {
    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> tsize[i];
    }
    cin >> T >> P;
    long long set = 0;
    long long num = 0;
    checkP(set, num);
    cout << checkT() << '\n' << set << ' ' << num;
}