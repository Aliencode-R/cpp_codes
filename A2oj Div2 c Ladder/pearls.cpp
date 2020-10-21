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

const int Max = 110;
int n; 
int cnt[Max], price[Max];
int dp[Max][Max];

int helper(int i, int last, int prevSum = 0) {
    if(i == n) {
        if(last != i) {
            return imax;
        }
        return 0;
    }

    int &ret = dp[i][last];
    if(ret != -1) return ret;

    ret = helper(i+1, i+1, 0) + (prevSum + cnt[i] + 10) * price[i];

    ret = min(ret, helper(i+1, last, prevSum + cnt[i]));

    return ret;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> cnt[i] >> price[i];
        }
        memset(dp, -1, sizeof dp);
        cout << helper(0, 0) << endl;
    }

    return 0;
}