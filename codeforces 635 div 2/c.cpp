#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
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
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;
const int N = 200005;        
vector<int> g[N];
int lvl[N];
int subtree[N];

int dfs(int node, int par, int l) {
    int res = 0;
    for(int nbr : g[node]) {
        if(nbr != par)
            res += dfs(nbr, node, l+1);
    }
    subtree[node] = res;
    lvl[node] = l;
    return res + 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1, 0);
    vector<int> v; 
    for(int i = 0; i< n; i++) v.push_back(lvl[i] - subtree[i]);
    sort(rall(v));
    int sum = 0;
    for(int i = 0; i < k; i++) sum += v[i];
    cout << sum;
    return 0;
}