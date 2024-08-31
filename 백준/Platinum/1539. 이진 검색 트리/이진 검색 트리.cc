#include <iostream>
#include <set>

using namespace std;

int height[250002];
long long total;
set<int> s;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    
    while (n--) {
        int num; 
        cin >> num;
        auto it = s.lower_bound(num);
        
        if (it == s.begin()) {
            height[num] = height[*it] + 1;
        } else if (it == s.end()) {
            height[num] = height[*prev(it)] + 1;
        } else {
            height[num] = max(height[*it], height[*prev(it)]) + 1;
        }
        
        s.insert(num);
        total += height[num];
    }
    
    cout << total;
}