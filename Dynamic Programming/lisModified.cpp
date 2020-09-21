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

int helper(int *a, int *wt, int n) {
    
    for(int i = 0; i < n; i++) {
        int mx = 0;
        for(int j = i-1; j >= 0; j--) {
            if(a[j] < a[i]) {
                mx = max(mx, wt[j]);
                // mx = wt[j];
                // break;
            }
        }
        wt[i] += mx;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, wt[i]);
    }
    return ans;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n; 
        int a[n]; int wt[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> wt[i];

        cout << helper(a, wt, n) << endl;

    }
    return 0;
}