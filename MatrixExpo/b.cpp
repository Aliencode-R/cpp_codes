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

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> res = {{0, 0}, {0, 0}};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                res[i][j] += (a[i][k] * b[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<int>> helper(vector<vector<int>> a, int n)
{
    vector<vector<int>> res = {{1,0}, {0,1}};
    while(n > 0) {
        if(n%2 == 1) {
            res = multiply(res,a);
        }
        n /= 2;
        a = multiply(a,a);
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> a = {{19,7},{6,20}};
    vector<vector<int>> res = helper(a, n);

    cout << res[0][0] ;
    return 0;
}