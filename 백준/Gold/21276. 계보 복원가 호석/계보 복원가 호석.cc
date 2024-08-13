#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

unordered_map<string, int> deg;
unordered_map<string, vector<string>> childList;
unordered_map<string, vector<string>> child;

int N, M;

int main() {
    cin >> N;
    vector<string> person(N);
    for (int i = 0; i < N; i++) {
        cin >> person[i];
    }
    sort(person.begin(), person.end());
    cin >> M;
    while (M--) {
        string s1, s2; cin >> s1 >> s2;
        ++deg[s1];
        childList[s2].push_back(s1);
    }
    vector<string> parent;
    queue<string> q;
    for (int i = 0; i < N; i++) {
        if (deg[person[i]] == 0) {
            parent.push_back(person[i]);
            q.push(person[i]);
        }
    }
    cout << parent.size() << "\n";
    for (auto &s : parent)
        cout << s << " ";
    cout << "\n";

    while (!q.empty()) {
        string s = q.front(); q.pop();
        for (auto &a : childList[s]) {
            if (--deg[a] == 0) {
                child[s].push_back(a);
                q.push(a);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << person[i] << " " << child[person[i]].size() << " ";
        sort(child[person[i]].begin(), child[person[i]].end());
        for (auto & a : child[person[i]])
            cout << a << " ";
        cout << "\n";
    }
}