#pragma GCC optimize ("O3")
/*#pragma GCC optimize ("O3")
#pragma GCC target("avx2")*/
#include<bits/stdc++.h>
using namespace std;

const long long p = 43, mod = 1e9 + 7, MAX_N = 210000;
string s;
long long powers[MAX_N] = {};
long long f[MAX_N] = {};

long long get_hash(int l, int r) {
    long long large = f[r];
    long long small = (l ? (f[l - 1] * powers[r - l + 1]) % mod : 0);
    return (large - small + mod) % mod;
}


int main() {
    freopen("palindrome.in", "r", stdin);
    freopen("palindrome.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    powers[0] = 1;
    for (int i = 1; i < MAX_N; i++) powers[i] = p * powers[i - 1] % mod;
    for (int i = 1; i < s.size(); i++) {
        f[i] = (f[i - 1] * p + s[i]) % mod;
    }
}
