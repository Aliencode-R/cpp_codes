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
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        // n++;
        int arr[n+1];
        for(int i = 1; i <= n; i++) cin >> arr[i];
        int f[n+1], ans[n+1], last[n+1];
        memset(f, 0, sizeof f);
        memset(last, 0, sizeof last);
        memset(ans, -1, sizeof ans);

        for(int i = 1; i <= n; i++) {
            int x = arr[i];
            f[x] = max(f[x], i - last[x]);
            last[x] = i;
        }
        for(int x = 1; x <= n; x++) {
            f[x] = max(f[x], n - last[x] + 1);
            for(int i = f[x]; i <= n and ans[i] == -1; i++) {
                ans[i] = x;
            }
        }

        // for(int x : ans) cout << x << " ";
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}