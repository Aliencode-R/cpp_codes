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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n; 
        for(int i = 1; i <= n; i++) {
            cout  << 1 <<" " ;
        }
        // int a = 1, b = 2;
        // if(n >= 1) {
        //     cout << 1 << " ";
            
        // }
        // if(n >= 2) {
        //     cout << 2 << " ";
        // }
        // for(int i = 1; i <= n-2; i++) {
        //     int c = a + b + 1;
        //     cout << c << " " ;
        //     a = b;
        //     b = c;
        // }
        cout << endl;
    }
    return 0;
}