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
    int n, k; cin >> n >> k;
    int i = 1, j = n, count = 1;
    int last = 0;
    while(count < k) {
        cout << i ++ << " ";
        count++;
        last = 0;
        if(count < k) {
            cout << j-- << " " ;
            count++;
            last = 1;
        }
    }
    if(last == 0) {
        for(int k = j; k >= i; k--) {
            cout << k << " ";
        }
    } else {
        for(int k = i; k <= j; k++) {
            cout << k << " ";
        }
    }
    return 0;
}