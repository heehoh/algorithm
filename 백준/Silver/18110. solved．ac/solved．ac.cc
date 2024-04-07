#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int x = floor(n * 0.15 + 0.5);
    double sum = 0;
    for (int i = x; i < n - x; i++)
    {
        sum += v[i];
    }
    cout << floor(sum / (n - 2 * x) + 0.5);
}