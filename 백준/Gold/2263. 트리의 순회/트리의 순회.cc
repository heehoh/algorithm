#include <iostream>
using namespace std;
int idx[100001];
int inorder[100001];
int postorder[100001];

void preorder(int inSt, int inEn, int postSt, int postEn) {
    if (inSt > inEn || postSt > postEn)
		return;
    int root = postorder[postEn];
    int rootIdx = idx[root];
    int leftTreeSize = rootIdx - inSt;
    
    cout << root << " ";
    preorder(inSt, rootIdx - 1, postSt, postSt + leftTreeSize - 1);
    preorder(rootIdx + 1, inEn, postSt + leftTreeSize, postEn - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i; // 원소의 인덱스 저장, 이후 postorder에서 root를 알 수 있어 root의 인덱스를 구하기 위함
    }
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }
    
    preorder(1, n, 1, n);
}