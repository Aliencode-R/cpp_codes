
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
        int arr[n+1];
        for(int i = 1; i <=n; i++) cin >> arr[i];
        bool flag = false;
        int count = 0;
        int segcount = 0;
        for(int i = 1; i <= n; i++) {
            if(arr[i] == i) {
                flag = false;
                count ++;
            }
            if(flag == false and arr[i] != i) {
                flag = true;
                segcount++;
            }
        }

        // for(int i = 1; i <=n; i++) {
        //     cout << i << "->" << arr[i] << endl;
        // }

        debug(count);
        if(count == n) {
            cout << 0 << endl;
        } else if(count == 0) {
            cout << 1 << endl;
        } else {
            if(segcount == 1) {
                cout << 1 << endl;
            } else
            cout << 2 << endl;
        }
    }
    return 0;
}




