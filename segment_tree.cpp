#pragma GCC optimize ("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> h((int)300000);

struct Node {
    int l, r, max_height;
    Node *left, *right;
    Node(int l, int r): l(l), r(r), left(0), right(0) {};
};

typedef Node* PNode;

PNode build(int l, int r) {
    PNode root = new Node(l, r);
    if (l == r) {
        root->max_height = h[l];
        return root;
    }
    int m = (l + r) / 2;
    root->left = build(l, m);
    root->right = build(m + 1, r);
    root->max_height = max(root->left->max_height, root->right->max_height);
    return root;
}

int query(PNode root, int l, int r) {
    if (root->r < l || root->l > r) return -1;
    if (root->l >= l && r >= root->r) return root->max_height;
    return max(query(root->left, l, r), query(root->right, l, r));
}

signed main() {
    freopen("mushrooms.in", "r", stdin);
    freopen("mushrooms.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> h[i];
    PNode root = build(0, n - 1);
    int m; cin >> m;
    int r, R; cin >> r >> R;
    long long ans = 0;
    while(m--) {
        int H = query(root, r, R);
        ans += H;
        int q = (1LL * r * H % n + 1LL * H * H % n) % n;
        r = min(R, q), R = max(R, q);
    }
    cout << ans;
}
