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
struct razor_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<int64_t, int64_t> Y) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};
int nc2(int n) {
    return ( n * (n - 1)) / 2;
}
void solve () {
    int a; cin >> a;
    string s; cin >> s ;
    int n = sz(s);
    int arr[n+1] = {};
    for(int i = 1; i <= n; i++) {
        arr[i] = arr[i-1] + (s[i-1] - '0');
    }
    // for(int i : arr) cout << i << " ";
    map<int, int> m;
    for(int i = 1; i <= n; i++) { 
        for(int j = i; j <= n; j++) {
            m[arr[j] - arr[i-1]] ++;
        }
    }
    // for(pii p : m) cout << p.first << " " << p.second << endl;
    int ans = 0;
    for(int i = 1; i * i <= a; i++) {
        if(a % i != 0) continue;
        if(i * i == a) {
            ans += m[i] * m[i];
        } else {
            ans += 2 * (m[i] * m[a/i]);
        }
    }

    if(a == 0) {
        
        ll total = n * 1LL * (n + 1) / 2;
        ll zero = cnt[0];
        ll non_zero = total - zero;
        cout<< zero * non_zero * 2 + zero * zero;
        return;
    }

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