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

int mcm(vector<int> arr) {
    int dp[200][200];
    memset(dp, 0, sizeof(dp));
    int n = arr.size() - 1;
    // cout << n << " ";
    for(int i = 1; i < n; i++) {
        // moving diagonally left-down from every col
        int r = 0, c = i; 
        while(c < n) {
            int val = INT_MAX;
            for(int pivot = r; pivot < c; pivot ++) {
                val = min(val, dp[r][pivot] + dp[pivot+1][c] + arr[r]*arr[pivot+1]*arr[c+1]);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }
    return dp[0][n-1];

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    cout << mcm(arr) << endl;

    return 0;
}