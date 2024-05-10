#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int N = str.length();
    
    int row, col;
    for (int i = 1; i < N; i++) {
        if (N % i == 0) {
            int tmp = i;
            if (tmp <= N / tmp) {
                row = tmp;
                col = N / row;
            }
        }
    }
    string answer;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            answer += str[j * row + i];
        }
    }
    cout << answer;
}