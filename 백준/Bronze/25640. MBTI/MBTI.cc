#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n; cin >> n;
    int cnt = 0;
    while (n-- > 0)
    {
        string s2; cin >> s2;
        if (s == s2)
        {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}