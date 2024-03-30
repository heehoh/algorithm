#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n; cin >> k >> n;
    vector<int> arr;
    while (k-- > 0) {
        int length; cin >> length;
        arr.push_back(length);
    }
 
    // min max 구하기
    int max = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (max < arr[i])
            max = arr[i];
    }
    
    // 이분 탐색
    long long left = 1;
    long long right = max;
    long long result = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += (arr[i] / mid);
        }
        if (sum >= n) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result;
    return 0;
}