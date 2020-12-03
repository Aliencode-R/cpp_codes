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

vector<pii> ans;
void solve () {
    int n, m, v; cin >> n >> m >> v;
    int p = n - 1;
    int edges = 1 + (p * (p - 1)) / 2;
    if(m > edges or m < n - 1) {
        cout << -1 << endl;
        return;
    }
    if(m == 0) return;
    int edge = 1;
    if(v == 1) {
        // ans.push_back({2,v});4
        cout << 2 << " " << v << endl;
    } else {
        // ans.push_back({1,v});
        cout << 1 << " " << v << endl;
    }

    for(int i = 2; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(edge == m) break;

            int x, y;
            if(i == 2) {
                x = v;
            } else if(i == v) {
                x = 2;
            } else {
                x = i;
            }
            if(j == 2) {
                y = v;
            } else if(j == v) {
                y = 2;
            } else {
                y = j;
            }
            // ans.push_back({x, y});
            cout << x << " " << y << endl;
            edge++;
        }
    }
    return;

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