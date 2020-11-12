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
const int N = 100001;        
vector<int> g[N];
vector<int> leaves;
int root;
int level[N];

void dfs(int node, int par, int lvl) {
    level[node] = lvl;
    for(int nbr : g[node]) {
        if(nbr != par) {
            dfs(nbr, node, lvl+1);
        }
    }
}

void dfs2(int node, int &x, int par = -1) {
    int count = 0;
    for(auto nbr : g[node]) {
        if(nbr != par) {
            dfs2(nbr, x, node);
            if(g[nbr].size() == 1) count++;
        }
    }
    if(count >= 1) x++;
}

void solve () {
    int n; cin >> n; 
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(sz(g[i]) == 1) leaves.push_back(i);
        else root = i;
    }
    dfs(leaves[0], -1, 0);
    int mn = 1, mx = imin;
    for(int leaf : leaves) {
        if(level[leaf] % 2 == 1)
            mn = 3; 
    }
    int x = 0;
    dfs2(root, x);

    cout << mn << " " << n - 1 - sz(leaves) + x;
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