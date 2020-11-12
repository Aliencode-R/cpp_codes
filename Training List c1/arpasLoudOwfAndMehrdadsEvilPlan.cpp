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
#define int long long

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

vector<int> g[101];
vector<int> vis(101, 0);

int dfs(int node) {
    // cout << node << " ";
    if(vis[node]) {
        return 0;
    }
    vis[node] = true;
    for(auto nbr : g[node]) {
        return 1 + dfs(nbr);
    }
    return 0;
}



void solve () {
    int n; cin >> n;
    int indegree[n+1]= {};
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        indegree[num]++;
        g[i].push_back(num);
    } 
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            cout << -1;
            return;
        }
    }
    vector<int> lens;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == false) {
            // cout << i << ":" ;
            int len = dfs(i);
            // cout << endl;
            // cout << len << ",";
            if(len % 2 == 0) len /= 2;
            lens.push_back(len);
        }
        // cout << endl;
    }
    // cout << endl;
    
    int ans = 1;
    for(int x : lens) {
        // cout << x << " " ;
        ans = (ans * x) / __gcd(ans, x);
    }
    // cout << endl;
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