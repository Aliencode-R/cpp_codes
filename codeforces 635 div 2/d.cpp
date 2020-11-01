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
bool flag = false;
int arr[31][31];
void helper(int n, int a, int b) {
    if(n <= 0) {
        flag = true;
        return;
    }
    if(flag) return;
    if(arr[a][b] != -1) return;
    if(a > 0)
    helper(n/2 + 10, a-1, b);
    if(b > 0)
    helper(n-10, a, b-1);
    arr[a][b] = 0;
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;
    while(t--) {
        memset(arr, -1, sizeof arr);

        int n, a, b; cin >> n >> a >> b;
        flag = false;
        helper(n, a, b);
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}