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

    int n; cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target; cin >> target;

    bool dp[n+1][target+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            if(i == 0 and j == 0) {
                dp[i][j] = 0;
            } else if(i == 0) {
                dp[i][j] = false;
            } else if(j == 0) {
                dp[i][j] = true;
            } else {
                dp[i][j] = dp[i-1][j];
                int val = arr[i-1];
                if(j >= val) {
                    dp[i][j] = dp[i][j] or dp[i-1][j - val];
                }
            }
        }
    }
    cout << (dp[n][target] ? "true" : "false");

    return 0;
}