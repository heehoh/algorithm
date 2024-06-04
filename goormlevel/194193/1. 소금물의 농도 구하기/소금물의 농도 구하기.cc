#include <iostream>
#include <iomanip>

using namespace std;
int main() {
	int N, M; cin >> N >> M;
	double salt = N * 0.07;
	double rate = salt / (N + M) * 100 - 0.005;
	cout << fixed << setprecision(2) << rate;
}