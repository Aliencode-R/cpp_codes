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

int n, k;
int dp[10001][201][2];
int arr[10001];

bool helper(int i, int op, int sum) {
    if(i == n) {
        return sum % k == 0;
    }
    sum %= k;
    int &ret = dp[i][sum + k][op];
    if(ret != -1) {
        return ret;
    }

    if(op == 0) {
        sum += arr[i];
        sum %= k;
    } else {
        sum -= arr[i];
        sum %= k;
    }
    sum += k;
    sum %= k;
    bool op1 = helper(i+1, 0, sum);
    bool op2 = helper(i+1, 1, sum);
    
    if(op1 or op2) {
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        cin >> n >> k;

        for(int i = 0; i < n; i++) cin >> arr[i];

        memset(dp, -1, sizeof dp);
        bool sp = helper(1, 1, arr[0]);

        // cout << endl;

        memset(dp, -1, sizeof dp);
        bool sm = helper(1, 0, arr[0]);
            // or
        if (sp or sm)
        {
            cout << "Divisible" << endl;
        }
        else
        {
            cout << "Not divisible" << endl;
        }
    }
    return 0;
}