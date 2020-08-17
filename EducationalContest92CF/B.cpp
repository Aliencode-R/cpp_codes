#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, k , z; cin >> n >> k >> z;
        int arr[n];
        for(int i= 0; i < n; i++) {
            cin >> arr[i];
        } 
        // arr[n] = 0;
        int ans = 0;
        for(int j = 0; j <= z; j++) {
            int mx = imin;
            int sum = 0;
            for(int i = 0; i <= k - 2*j; i++) {
                mx = max(mx, arr[i]+arr[i+1]);
                sum += arr[i];
            }
            ans = max(ans , sum + j * mx);
        }
        cout << ans << endl;

    }
    return 0;
}
