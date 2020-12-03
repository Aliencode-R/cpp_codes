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
    int n, t; cin >> n >> t; 
    string str1, str2;
    cin >> str1 >> str2;
    string ans = str1;
    int same = 0, different = 0;
    for(int i = 0; i< n; i++) {
        if(str1[i] == str2[i]) {
            same++;
        } else {
            different++;
        }
    }
    if(t < different) {
        cout << -1 ;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(t == 0) break;
        if(str1[i] != str2[i]) {
            if(str1[i] != 'a' and str2[i] != 'a') {
                ans[i] = 'a';
            }
            else if (str1[i] != 'b' and str2[i] != 'b') {
                ans[i] = 'b';
            }
            else if (str1[i] != 'c' and str2[i] != 'c')
            {
                ans[i] = 'c';
            }
            t--;
        }
    }
    if(t > 0) {
        for(int i = 0; i< n; i++) {
            if(t == 0) {
                break;
            }
            if(str1[i] == str2[i]) {
                if(str1[i] == 'a') {
                    ans[i] = 'b';
                } else {
                    ans[i] = 'a';
                }
                t--;
            }
        }
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