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

struct node {
    int x, y, z;
};

bool check(int len, int x, int y, int z) {
    if(len <= 2) return true;
    vi v = {x, y, z};
    sort(all(v));
    int m = len % 3;
    if(m == 0) {
        if(v[0] == v[1] and v[0] == v[2]) {
            return true;
        }
        return false;
    } 
    if(m == 1) {
        if(v[0] == v[1] and v[0] + 1 == v[2]) {
            return true;
        }
        return false;
    }
    if(m == 2) {
        if(v[1] == v[2] and v[0] + 1 == v[1]) {
            return true;
        }
        return false;
    }
    return true;
}

void solve () {
    // int x = 0, y = 0, z = 0;
    string s; cin >> s; 
    int n = sz(s);
    vector<node> v(n+1);
    for(int i = 1; i <= n; i++) {
        v[i].x = v[i - 1].x + (s[i - 1] == 'x');
        v[i].y = v[i-1].y + (s[i-1] == 'y');
        v[i].z = v[i - 1].z + (s[i - 1] == 'z');
    }
    // for(int i = 0; i <= n; i++) {
    //     cout << v[i].x << " " << v[i].y << " " << v[i].z << endl;
    // }
    int q; cin >> q; 
    while(q--) {
        int l, r; cin >> l >> r;
        cout << (check(r - l + 1, v[r].x - v[l - 1].x, v[r].y - v[l - 1].y, v[r].z - v[l - 1].z) ? "YES" : "NO") << endl;
    }
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