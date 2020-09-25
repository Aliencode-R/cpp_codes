#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int arr[m]; 
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    int ans[n+1];
    memset(ans, -1, sizeof ans);
    bool flag = true;
    for(int i = 1; i < m; i++) {
        int index = arr[i-1];
        int val = arr[i] - arr[i-1];
        if(val <= 0) {
            val += n ;
        }
        if(ans[index] == -1) {
            ans[index] = val;
        } else {
            flag = false;
            break;
        }
    }
    for(int i = 1; i <= n; i++) if(ans[i] == -1) flag = false;
    if(flag and n < m) {
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    } else {
        cout << -1;
    }
    return 0;
}