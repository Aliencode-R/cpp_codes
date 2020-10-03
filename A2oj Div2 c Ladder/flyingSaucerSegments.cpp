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

ll recpow(ll n, ll p, ll m)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1){
            ans = ans * n ;
            ans %= m;
        }
        n = n * n ;
        n %= m;
        p >>= 1;
        // p %= m;
    }
    return ans % m;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int a = (recpow(3, n, m)  + m - 1) % m;
    cout << a;
    return 0;
}