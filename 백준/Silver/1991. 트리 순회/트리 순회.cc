#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char left;
    char right;
};

void preorder(vector<Node> &v, char c) {
    if (c == '.')
        return;
    
    cout << c;
    preorder(v, v[c - 'A'].left);
    preorder(v, v[c - 'A'].right);
}

void midorder(vector<Node> &v, char c) {
    if (c == '.')
        return;
 
    midorder(v, v[c - 'A'].left);
    cout << c;
    midorder(v, v[c - 'A'].right);
}

void lastorder(vector<Node> &v, char c) {
    if (c == '.')
        return;
    
    lastorder(v, v[c - 'A'].left);
    lastorder(v, v[c - 'A'].right);
    cout << c;
}

int main() {
    int N; cin >> N;
    vector<Node> v(N);
    for (int i = 0; i < N; i++) {
        char parent, left, right; cin >> parent >> left >> right;
        v[parent - 'A'].left = left;
        v[parent - 'A'].right = right;
    }
    preorder(v, 'A');
    cout << '\n';
    midorder(v, 'A');
    cout << '\n';
    lastorder(v, 'A');
}