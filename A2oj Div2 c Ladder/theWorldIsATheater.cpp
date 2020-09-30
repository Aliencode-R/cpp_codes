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

// int dp[61][61];

int printNcR(int n, int r)
{

    // if(dp[n][r] != -1) return dp[n][r];

    long long p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else
        p = 1;

    return  p;
   
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // memset(dp, -1, sizeof dp);
    int b, g, t; cin >> b >> g >> t;
    int sum = 0;
    int boy = printNcR(b, 4);
    int c = min(t, g);
    int girl = printNcR(g, c - 4);
    sum += boy * girl;
    for(int i = 5; i < t; i++) {
        
        if(i > b or 

    }
    cout << sum;
    return 0;
}