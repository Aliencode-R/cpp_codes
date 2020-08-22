#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long
vector<int> g[100010];
vector<int> k;
unordered_map<int,int> m;

void dfs(int src, int par, int edgeNo) {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int u, v; cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int m; cin >> m;
    k.reserve(m);
    for(int i = 0 ;i < m; m++) {
        cin >> k[i];
    }
    dfs(1, -1, 1);

    return 0;
}