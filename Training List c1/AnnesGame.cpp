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
#define mod 2000000011
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

int helper(int a, int n) {
    if(n == 0) return 1;
    if(n == 1) return a;

    int x = helper(a, n / 2) % mod;
    x = (x * x) %  mod;

    if(n % 2 == 1) {
        return (x * a) % mod;
    } else {
        return (x) % mod;
    }
}

long long mod_pow(long long a, int b)
{
    long long ret = 1;

    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    for(int i = 1; i <= t; i++) {
        int n ; cin >> n;
        int ans = n == 1 ? 1 : helper(n, n-2);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}