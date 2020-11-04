#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        // int n; cin >> n; 
        int a, b; 
        cin >> a >> b; 
        string s; cin >> s;
        int n = s.size();
        if(n == 1) {
            if(s[0] == '0') {
                cout << 0 << endl;
            } else {
                cout << a << endl;
            }
            continue;
        }
        pii dp[n];
        if( s[0] == '0' and s[1] == '1'){
            dp[0] = {0, 0};
            dp[1] = {a, a};
        }
        else if (s[0] == '0' and s[1] == '0') {
            dp[0] = {0, 0};
            dp[1] = {0, 0};
        }
        else if (s[0] == '1' and s[1] == '1')
        {
            dp[0] = {a, a};
            dp[1] = {a, a};
        } 
        else {
            dp[0] = {a, a};
            dp[1] = {a+b, a};
        }
        for(int i = 2; i < n; i++) {
            if(s[i] == '0') {
                if(s[i-1] == '0') { // 0 0 
                    dp[i].first = dp[i-1].first + b;
                    dp[i].second = dp[i-1].second ;
                } else {  // 1 0
                    dp[i].first = dp[i-1].first + b;
                    dp[i].second = min(dp[i - 1].first, dp[i-1].second);
                }
            } else {
                if (s[i - 1] == '0') // 0 1
                {
                    dp[i].first = dp[i - 1].second + a;
                    dp[i].second = dp[i - 1].first;
                }
                else
                { // 1 1
                    dp[i].first = dp[i - 1].first;
                    dp[i].second = dp[i - 1].second;
                }
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << dp[i].first << "," << dp[i].second << endl;
        // }
        cout  << min(dp[n-1].first, dp[n-1].second) << endl;
    }
    return 0;
}