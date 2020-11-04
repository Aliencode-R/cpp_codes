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
    int count = 0;
    int n, a, b; cin >> n >> a >> b;
    if(a == n-1  and n != 1) {
        cout << -1 ;
        return 0;
    }
    if(n == 1){
        cout << 1 ;
        return 0;
    }
    cout << 1 << " " ;
    int val = 2;
    for(int i = 1; i <= b; i++) {
        cout << val << " ";
        if(i != b)
            val = val * 2 + 1;
    }
    if(b == 0) {
        cout << 1 << " " ;
        b++;
        int val = 1;
        for(int i = 1; i <= a; i++) {
            cout << ++val << " " ;
        }
    }
    else {
        for(int i = 1; i <= a; i++) {
    
            cout << ++val << " ";
        }
    }
    for(int i = 1; i <= n - a - b - 1; i ++) {
        cout << 1 << " ";
    }



    return 0;
}