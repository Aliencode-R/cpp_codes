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

bool check(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n; cin >>n ;
        int p1, p2;
        bool flag = false;
        for(int i = 1; i < 10000000; i++) {
            if(flag)break;
            if(check(n-1 + i) and !check(i)) {
              for(int j = 1; j < 10000000; j++) {
                  if(check(n - 2 + i + j) and !check(j))
                  {
                    p1 = i;
                    p2 =  j;
                    flag = true;
                    break;
                  }
              }
            }
        }
        int arr[n][n];
        // memset(arr, 1, sizeof arr);
        for(int i = 0; i <n; i++) 
        for(int j = 0; j <n; j++) arr[i][j] = 1;

        for(int i = 0; i <n-2; i++) {
            for(int j = 0; j < n-2; j++) {
                arr[i][j] = 0;
            }
        }
        arr[n-1][n-2] = p1;
        arr[n-2][n-1] = p1;
        arr[n-1][n-1] = p2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << arr[i][j] << " " ;
            }
            cout << endl;
        }
        // cout << endl;
    }
    return 0;
}