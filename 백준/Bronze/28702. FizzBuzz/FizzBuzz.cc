#include <iostream>

using namespace std;
string s;

int atoi(string& s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        num *= 10;
        num += s[i] - '0';
    }
    return num;
}

int main() {
    int num = 0;
    for (int i = 0; i < 3; i++) {
        cin >> s;
        if (s != "Buzz" && s != "Fizz" && s != "FizzBuzz"){
            num = atoi(s) + 3 - i;
            break;
        }
    }
    if (num % 3 == 0 && num % 5 == 0) {
        cout << "FizzBuzz";
    } else if (num % 3 == 0) {
        cout << "Fizz";
    } else if (num % 5 == 0) {
        cout << "Buzz";
    } else {
        cout << num;
    }
}