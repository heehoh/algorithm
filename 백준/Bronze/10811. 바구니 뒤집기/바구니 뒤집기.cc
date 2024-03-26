#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int box[n];

    for (int i = 0; i < n; ++i)
    {
        box[i] = i + 1;
    }

    while (m-- > 0)
    {
        int start, end; cin >> start >> end;
        --start;
        --end;
        while (start < end)
        {
            int tmp = box[start];
            box[start] = box[end];
            box[end] = tmp;
            ++start;
            --end;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << box[i] << " ";
}