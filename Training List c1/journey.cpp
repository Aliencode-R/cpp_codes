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
const int N = 100001;
vector<int> g[N];


double dfs(int par, int node) {
    double sum = 0;
    int count = 0;
    for(int nbr : g[node]) {
        if(nbr != par) {
            count++;
            sum += dfs(node, nbr) + 1;
        }
    }
    if(count == 0) return 0;
    return sum / count;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; 
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; 
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int paths = g[1].size();
    double totalLen = 0;
    // for(int nbr : g[1]) {
    //     totalLen += dfs(1, nbr) + 1;
    // }
    cout << fixed << setprecision(6) << dfs(0, 1);
    return 0;
}

