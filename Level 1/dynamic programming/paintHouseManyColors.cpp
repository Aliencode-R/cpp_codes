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
    int n, k; cin >> n >> k;
    int arr[n][k]; 
    int dp[n][k]; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> arr[i][j];
        }
    }
    int least = imax, secLeast = imax;
    for(int i = 0; i < k; i++) {

        dp[0][i] = arr[0][i];

        if(arr[0][i] <= least) {
            secLeast = least;
            least = arr[0][i];
        } else if(arr[0][i] <= secLeast) {
            secLeast = arr[0][i];
        }

    }
    for(int i = 1; i < n; i++) {

        int newLeast = imax, newSecLeast = imax;

        for(int j = 0; j < k; j++) {

            if(least == dp[i-1][j]) {
                dp[i][j] = secLeast + arr[i][j];
            } else {
                dp[i][j] = least + arr[i][j];
            }

            if(dp[i][j] <= newLeast) {
                newSecLeast = newLeast;
                newLeast = dp[i][j];
            } else if(dp[i][j] <= newSecLeast) {
                newSecLeast = dp[i][j];
            }
        }
        least = newLeast;
        secLeast = newSecLeast;
    }
    cout << least;
    return 0;
}
