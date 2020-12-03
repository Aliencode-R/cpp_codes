#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " = " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define sz(x) ((int)x.size())
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

void solve () {
    string s; cin >> s; 
    int cnt = 0;
    for(auto c : s) {
        if(c == '-') {
            cnt += (1);
        } else if(c == '_') {
            cnt += 0;
        } else if(c - '0' <= 9 and c - '0' >= 0) {
            cnt += ( 6 -__builtin_popcountll(c - '0'));
        } else if(c - 'a' <= 25 and c - 'a' >= 0) {
            cnt += (6 - (__builtin_popcountll(c - 'a' + 36)));
        }
        else if (c - 'A' <= 25 and c - 'A' >= 0)
        {
            cnt += (6 - (__builtin_popcountll(c - 'A' + 10)));
        }
        // cout << cnt << endl;
    }
    int ans = 1;
    for(int i = 1; i <= cnt; i++) {
        ans *= 3;
        ans %= mod;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}