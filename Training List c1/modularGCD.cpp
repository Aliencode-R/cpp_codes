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

ll power(ll b, ll p, ll m)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = (__int128) r * b % m;
        b = (__int128) b * b % m;
        p /= 2;
    }
    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int a, b, n; cin >> a >> b >> n;
        int m = a==b ? mod : a - b;
        int x = a - b;
        int y = ( power(a, n, m) + power(b, n, m) ) % m;
        cout << __gcd( x, y ) % mod << endl;
    }
    return 0;
}