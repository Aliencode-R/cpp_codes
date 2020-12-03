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
const int N = 2e5 + 5;
int n, k;
vi arr(N);

bool check(int curMin, int toggle) {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(toggle == 0) {
            toggle = 1;
            ans ++;
        } else {
            if(arr[i] <= curMin) {
                toggle = 0;
                ans ++;
            }
        }
    }
    return ans >= k;
}

int binsearch(int low, int high) {
    int ans = 1e9;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid, 0) or check(mid, 1)) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

void solve () {
    cin >> n >> k ;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cout << binsearch(1, 1e9);
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