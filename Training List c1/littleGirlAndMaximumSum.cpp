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

void solve () {
    int n, q; cin >> n >> q;
    vi diff(n + 1, 0);
    vi arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(rall(arr));
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; 
        l--, r--;
        diff[l]++; diff[r+1]--;
    }
    for(int i = 1; i <= n; i++) {
        diff[i] += diff[i-1];
    }

    sort(rall(diff));

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (diff[i] * arr[i]);
    }
    cout << sum;

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