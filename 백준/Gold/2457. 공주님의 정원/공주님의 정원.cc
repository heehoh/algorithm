#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.X == b.X)
        return a.Y > b.Y;
    return a.X < b.X;
}

int getDays(int month, int day) {
    int total = 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < month - 1; i++) {
        total += days[i];
    }
    return total + day;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; 
    cin >> N;
    int minBeginDay = getDays(3, 1);
    int minLastDay = getDays(12, 1);
    
    vector<pair<int, int>> flower;
    flower.reserve(N);
    for (int i = 0; i < N; i++) {
        int m, d; 
        cin >> m >> d;
        int st = getDays(m, d);
        cin >> m >> d;
        int en = getDays(m, d);
        flower.push_back({st, en});
    }
    
    sort(flower.begin(), flower.end(), cmp);

    int num = 0;
    int end = minBeginDay;
    int i = 0;

    while (end < minLastDay) {
        int maxEnd = end;
        while (i < N && flower[i].X <= end) {
            maxEnd = max(maxEnd, flower[i].Y);
            i++;
        }
        if (maxEnd == end) {
            cout << 0;
            return 0;
        }
        end = maxEnd;
        num++;
    }

    cout << num;
}