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
const int N = 1001;
int totStuffing[N];
int stuffingI[N];
int doughI[N];
int price[N];
int dp[11][1001];

int helper(int i, int total) {
    if(i == 0) {
        int buns = total / doughI[i];
        int sell = price[0] * buns;
        return sell;
    }
    int &ret = dp[i][total];
    if(ret != -1) return ret;
    // calc max buns this i can take and call from 0 to this number.
    int maxTake = min( total/doughI[i], totStuffing[i]/stuffingI[i] );

    for(int bun = 0; bun <= maxTake; bun++) {
        int tempSell = bun * price[i];
        int prevSell = helper(i - 1, total - doughI[i] * bun);
        ret = max(ret, tempSell + prevSell);
    }

    return ret;
}

void solve () {
    int total, m; cin >> total >> m;
    cin >> doughI[0] >> price[0];
    totStuffing[0] = infl;
    stuffingI[0] = 0;

    for(int i = 1; i <= m; i++) {
        cin >> totStuffing[i] >> stuffingI[i] >> doughI[i] >> price[i] ;
    }
    int ans = imin;
    memset(dp, -1, sizeof dp);
    helper(m, total);
    for(int i = 1; i <= 1000; i++) {
        ans = max(ans, dp[m][i]);
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