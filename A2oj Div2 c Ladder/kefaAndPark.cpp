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

int cat[N];
vector<int> g[N];

int dfs(int cur, int par, int catsTillNow, int maxCats) {
    
    if(cat[cur] == 0) {
        catsTillNow = 0;
    } else {
        catsTillNow ++;
    }

    if(catsTillNow > maxCats) return 0;

    bool isRoot = true;
    int count = 0;
    for(int child : g[cur]) {
        if(child == par) continue;
        isRoot = false;
        count += dfs(child, cur, catsTillNow, maxCats);
    }
    return count + isRoot;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> cat[i];
    }
    for(int i = 1; i < n;i ++) {
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);

    }
    cout << dfs(0, -1, 0, m);

    return 0;
}