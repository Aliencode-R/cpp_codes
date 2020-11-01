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
bool check(int arr[100][100], int n, int m, int low, int high) {
    while(low < high) {
        for(int i = 0; i < m; i++) {
            if(arr[low][i] != arr[high][i]) return false;
        }
        low++;
        high--;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    if(n&1) {
        cout << n << endl;
        return 0 ;
    }
    int arr[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = n ;
    while(n > 1 and n%2 == 0) {
        if(check(arr, n, m, 0, n-1)) {
            ans = n/2;
        }  
        else {
            break;
        }      
        n/=2;
    }
    cout << ans;

    return 0;
}