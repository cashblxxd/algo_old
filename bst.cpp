#include <bits/stdc++.h>

using namespace std;

struct Node {
  int key, prior, sum;
  Node * left = nullptr, * right = nullptr;
  Node(int key) {
    prior = rand();
    key = key;
    sum = key;
  }
}

int get_sum(Node & cur) {
  if (!root) return 0;
  return root->sum;
}

void update(Node & cur) {
  cur->sum = cur->key + get_sum(cur->left) + get_sum(cur->right);
}

void split(Node ** l, Node ** r, Node & root, int x) {
  if (!root) {
    *l = nullptr;
    *r = nullptr;
  }
  if (root->key < x){
    split(*root->right, *r, root->right, x);
    *l = root;
    update(l);
  } else {
    split(*l, *root->left, root->left, x);
    *r = root;
    update(r);
  }
}

int find_sum(Node * root, int l, int r) {
  Node * left, * middle, *right;
  split(*left, *middle, root, l);
  split(*middle, *right, middle, r);
  int ans = r->sum;
  merge(*middle, *right, middle);
  merge(*left, *middle, root);
  return ans;
}

void merge(Node & l, Node & r, Node ** root) {
  if(!l || !r){
    if (!l) *root = r;
    if (!r) *root = l;
    return;
  }
  if(l->prior > r->prior) {
    merge(l->right, r, l->right);
    *root = l;
  } else {
    merge(l, r->left, r->left);
    *root = r;
  }
  update(root);
}

signed main(){
  freopen("inverse.in", "r", stdin);
  freopen("inverse.out", "w", stdout);
  ios::sync_with_stdio(0);
  int n; cin >> n;
  int a[n];
  int ans = 0;
  for(auto & i : a) cin >> i;
  for (int i = 0; i < n; ++i)
    for(int j = 0; j < i; ++j)
      ans += (a[j] > a[i]);
  cout << ans;
}
