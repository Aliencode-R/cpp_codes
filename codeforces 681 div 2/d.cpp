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
        int a, b; cin >> a >> b; 
        string s; cin >> s; 
        int n = s.size();
        int start = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') break;
        }
        int ii;
        for(int i = start; i < n; i++) {
            if(s[i] == '0') {
                ii = i;
                break;
            }
        }
        vector<int> v;
        int p = a;
        int q = a;
        for(int i = ii; i < n; i++) {
            if(s[i] == '1' ) {
                int newp = min(q + b, p + a);
                int newq = 
            }

        }
    }
    return 0;
}