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

typedef tree<int, null_type, less<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

void solve () {
    int n, k; cin >> n >> k ;
    int arr[n]; 
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<set<int>> ans;
    for(int i = 0; i < n; i++) {
        if(k == 0) {
            break;
        }
        set<int> s;
        s.insert(arr[i]);
        ans.push_back(s);
        k--;
    }
    int sz = 1;
    sort(arr, arr+n, greater<int>());
    while(k > 0 and sz <= n) {
        set<int> s;
        for(int i = 0; i < sz; i++) {
            s.insert(arr[i]);
        }
        for(int i = sz; i < n; i++) {
            if(k == 0) break;
            s.insert(arr[i]);
            ans.push_back(s);
            s.erase(arr[i]);
            k--;
        }
        sz++;
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << " " ;
        for(auto x : ans[i]) cout << x << " ";
        cout << endl;
    }
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