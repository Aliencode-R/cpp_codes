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
// #define int long long
int n, total = 0;
int dp[105][50005];
int arr[105];

int helper(int i, int sum) {
    if(i == n) return abs(sum - (total - sum));

    int ret = dp[i][sum];
    if(ret != -1) return ret;

    ret = min(helper(i+1, sum), helper(i+1, sum + arr[i]));
    return ret;

}

// int solve(int idx, int cur_sum) {
// 	if (idx == n) return abs(cur_sum - (total - cur_sum));
// 	int &ret = dp[idx][cur_sum];
// 	if (ret != -1) return ret;
// 	ret = min(solve(idx + 1, cur_sum), solve(idx + 1, cur_sum + arr[idx]));
// 	return ret;
// }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        total = 0;
        for(int i = 0; i < n; i++)  {
            cin >> arr[i];
            total += arr[i];
        }
        
        memset(dp, -1, sizeof dp);
        cout << helper(0, 0) << endl;
    }
    return 0;
}