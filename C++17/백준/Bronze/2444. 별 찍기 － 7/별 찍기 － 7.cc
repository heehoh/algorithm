#include <iostream>
using namespace std;

void print_star(int star, int space) {
    while (space--)
        cout << " ";
    while (star--)
        cout << "*";
    cout << "\n";
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            print_star(2*i+1, n-i-1);
        } else {
            print_star((2*n-i)*2-3, i-n+1);
        }
    }
}