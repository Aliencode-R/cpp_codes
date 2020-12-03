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

class dsu
{
    vector<int> sz;
    int components;

public:
    vector<int> parent;
    dsu(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        components = n;
    }

    int getComponents()
    {
        return components;
    }

    int getSuperParent(int x)
    {
        // path compression
        if (parent[x] == x)
        {
            return x;
        }
        else
        {
            return parent[x] = getSuperParent(parent[x]);
        }
    }

    void unite(int x, int y)
    {
        int super_x = getSuperParent(x);
        int super_y = getSuperParent(y);

        if (super_x != super_y)
        {
            parent[super_x] = super_y;
            sz[super_y] += sz[super_x];
            sz[super_x] = 0;
            components--;
        }
    }
};

void solve () {
    int n, m; cin >> n >> m;
    dsu g(m);
    bool visited[m] = {};

    int ans = 0;
    int all0 = true;
    for(int i = 0; i < n; i++) {
        int s; cin >> s; 
        if(s == 0) {
            ans++;
        } else {
            all0 = false;
            if(s == 1) {
                int x; cin >> x;
                visited[x-1] = true;
            } else {
                int x; cin >> x;
                visited[x - 1] = true;
                x--;
                for(int j = 0; j < s - 1; j++) {
                    int y; cin >> y;
                    visited[y - 1] = true;
                    y--;
                    g.unite(x, y);
                }
            }
        }
    }
    debug(g.getComponents());
    if(all0) {
        cout << n << endl;
        return;
    }
    for(int i = 0; i < m; i++) {
        if(visited[i] == false) {
            ans--;
        }
    }
    cout << ans + g.getComponents() - 1 << endl;
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