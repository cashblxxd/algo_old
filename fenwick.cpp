#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
std::vector<int> fen(1e6 + 1);

void add(int i) {
  for(; i < 1e6 + 1; i += i & -i)
    fen[i] += 1;
}

int get(int l, int r=1e6) {
  int a = 0;
  if(l != 1) return get(1, r) - get(1, l - 1);
  for(; r > 0; r -= r & -r) a += fen[r];
  return a;
}

signed main() {
  freopen("inverse.in", "r", stdin);
  freopen("inverse.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i){
    cin >> k;
    ans += get(k + 2);
    add(k + 1);
  }
  cout << ans;
}
