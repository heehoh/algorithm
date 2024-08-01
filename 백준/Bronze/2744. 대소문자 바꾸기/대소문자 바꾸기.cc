#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    for (auto c : s) {
        if (c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';
        else
            c = c - 'A' + 'a';
        cout << c;
        
    }
}