#include <iostream>
#include <set>

using namespace std;

class Node
{
    public:
        int _x;
        int _y;
        Node(int x, int y) : _x(x), _y(y) {}
        bool operator<(const Node& node) const
        {
            if (_x == node._x)
            {
                return _y < node._y;
            }
            return _x < node._x;
        }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<Node> s;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        s.insert(Node(x, y));
    }
    for (auto P : s)
    {
        cout << P._x << " " << P._y << "\n";
    }
    
}