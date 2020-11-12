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

void solve () {
    int n, k; cin >> n >> k;
    int arr[n+1][n+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            arr[i][j] = 0;
        }
    }

    int r, c;
    r = 1, c = 1;
    while(k > 0 and r <= n and c <= n) {
        arr[r][c] = 1;
        k--;
        r++, c++;
    }
    if(k > 0) {
        int p = 1;
        while(p <= n-1 and k > 0) {
            int r = 1, c = p + 1;
            while(k> 0 and r <= n and c <= n) {
                arr[r][c] = 1;
                r++;
                c++;
                k--;
            }
            r = p + 1, c = 1;
            while(k > 0 and r <= n and c <= n) {
                arr[r][c] = 1;
                r++;
                c++;
                k--;
            }
            p++;
        }
    }

    int maxr = imin, minr = imax, maxc = imin, minc = imax;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += arr[i][j];
        }
        maxr = max(sum, maxr);
        minr = min(sum, minr);
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += arr[j][i];
        }
        maxc = max(sum, maxc);
        minc = min(sum, minc);
    }

    cout << (pow(maxr-minr, 2) + pow(maxc - minc, 2)) << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return;

}

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