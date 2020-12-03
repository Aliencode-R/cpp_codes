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
    int n; cin >> n; 
    vi arr(n);
    for(int i = 0; i < n; i++ ) cin >> arr[i];
    if(n == 1) {
        cout << arr[0] << endl;
        return;
    }
    sort(all(arr));
    int sum = 0;
    for(int i = 0; i < n; i++) sum += 2 * arr[i];
    vi acc(n, 0);
    acc[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        acc[i] += acc[i + 1] + arr[i];
    }
     sum = 2 * acc[0];
    for(int i = 1; i < n-1; i++) {
        sum += acc[i];
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