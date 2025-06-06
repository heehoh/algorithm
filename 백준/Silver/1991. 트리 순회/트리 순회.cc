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

void inorder(vector<Node> &v, char c) {
    if (c == '.')
        return;
 
    inorder(v, v[c - 'A'].left);
    cout << c;
    inorder(v, v[c - 'A'].right);
}

void postorder(vector<Node> &v, char c) {
    if (c == '.')
        return;
    
    postorder(v, v[c - 'A'].left);
    postorder(v, v[c - 'A'].right);
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
    inorder(v, 'A');
    cout << '\n';
    postorder(v, 'A');
}