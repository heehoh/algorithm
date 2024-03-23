#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    int r;
    string res;
    while (n--) 
    {
        cin >> r >> s;
        for (auto c : s)
        {
            for (int i = 0; i < r; ++i)
            {
                res += c;
            }
        }
        res += '\n';
    }
    cout << res;
}