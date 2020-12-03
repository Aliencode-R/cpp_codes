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

void solve() {
    int n; cin >> n; 
    map<int,int> m; 
    for(int i = 0; i < n; i++) {
        int num; cin >> num; 
        m[num]++;
    }
    for(pii p : m) {
        if(p.second >1 ) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

// void solve () {
//     int n; cin >> n ;
//     int b[n+1];
//     int cnt = 0;
//     vi sum;
//     for(int i = 1; i<=n; i++) {
//         cin >> b[i];
//         if(b[i] == 0) {
//             cnt++;
//         }
//     }    
//     sum.push_back(0);
//     for(int i = 1; i <= n; i++) {
//         if(b[i] != 0) {
//             int last = sum[sz(sum) - 1];
//             sum.push_back(last + b[i]);
//         }
//     }
//     umap<int,int> m;
//     for(int i = 0; i < sz(sum); i++) {
//         for(int j = i + 1; j < sz(sum); j++) {
//             int tempSum = sum[j] - sum[i];
//             m[tempSum] ++;
//         }   
//     }
//     bool flag = false;
//     for(auto p : m) {
//         if(p.second >= 2) {
//             flag = true;
//             break;
//         }
//     }
//     if(flag or cnt >= 2) cout << "YES" << endl;
//     else cout << "NO" << endl;
// }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}