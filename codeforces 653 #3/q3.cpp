#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

ll fastModExp(ll a, ll b, ll m) {
    ll res = 1;
    while(b > 0) {
        if((b&1) == 1) {
            res = (res*a) ;
            res %= m;
        }
        a = (a*a)%m;
        b = (b>>1);
    }
    return res;
}

ll solve(ll n, ll p) {
    ll ans = -1;
    for(ll i = n+1; i <= p-1; i++) {
        ll temp = fastModExp(i, p-2, p);
        ans = (ans*temp)%p;
    }
    return ans+p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, p; cin >> t;
    while(t--) {
        cin >> n >> p;

        if(n >= p) { 
            cout << "0" << endl;
        }
        else {
            cout << solve(n, p) << endl;
        }
    }

    return 0;
}
