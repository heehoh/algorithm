#include <iostream>
#include <unordered_map>
using namespace std;

int num;

class Node {
public:
    unordered_map<char, Node*> m;
};

void insert(Node &node, const string &s, int dep) {
    if (dep == s.length()) {
        return;
    }
    if (node.m.find(s[dep]) == node.m.end()) {
        node.m[s[dep]] = new Node();
    }
    insert(*node.m[s[dep]], s, dep + 1);
}

void find(Node &node, const string &s, int dep) {
    if (dep == s.length()) {
        ++num; 
        return;
    }
    if (node.m.find(s[dep]) != node.m.end()) {
        find(*node.m[s[dep]], s, dep + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M; 
    cin >> N >> M;

    Node head;
    
    while (N--) {
        string s; 
        cin >> s;
        insert(head, s, 0);
    }
    
    while (M--) {
        string s; 
        cin >> s;
        find(head, s, 0); 
    }
    cout << num;

    return 0;
}