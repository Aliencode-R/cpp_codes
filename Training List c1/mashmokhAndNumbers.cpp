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
int a, b;
void solve () {
    int n, k; cin >> n >> k;
    int m = n; 
    if(n == 1) {
        if(k == 0) {
            cout << 1 << endl;
            return;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    if(k < n / 2) {
        cout << -1;
        return;
    }
    if(m&1) m--;
    int p = m - 2;
    // if(p != 0) {
        a = k - p / 2;
        b = 2 * a;
        if(b > 1e9) {
            cout << -1 ;
            return;
        }
        cout << a << " " << b << " ";

    // }
    for(int i = 1; i <= p; i++) {
        cout << ++b << " ";
    }
    if(n & 1) cout << ++b;
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