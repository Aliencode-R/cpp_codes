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
vector<int> arr(1000005,0);
vector<int> dp(1000005, 0);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num]++;
    }
 
    dp[1] = arr[1];
    for(int i = 2; i <= 100000; i++) {
        // op1 
        int op1 = i * arr[i] + dp[i-2];
        // op2
        int op2 = dp[i-1];
        dp[i] = max(op2, op1);
    }

    cout << dp[100000];
    return 0;
}
