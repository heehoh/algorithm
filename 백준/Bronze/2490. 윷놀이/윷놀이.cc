#include <iostream>
using namespace std;
int main() {
    for (int j = 0; j < 3; j++) {
        int num = 0;
        for (int i = 0; i < 4; i++) {
            int a; cin >> a;
            if (a == 0)
                ++num;
        }
        if (num == 0) {
            cout << "E\n"; 
        }
        else
            cout << (char)('A' + num - 1) << "\n";
    }
}