#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int, int>
#define mii map<pii, int>
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define endl '\n'
#define hell 1000000007
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

// Most important thing in CP - Have Fun :)

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //insert code
    ll n;
    cin >> n;
    vector<ll> arr(n + 1);
    rep(i, 1, n + 1) cin >> arr[i];
    vector<ll> xorval(n + 1, 0);
    rep(i, 1, n + 1) xorval[i] = i ^ xorval[i - 1];
    // for(int x : xorval) cout << x << "-";
    // cout << endl;
    ll ans = 0;
    rep(i, 1, n + 1)
    {
        int cycles = n / i;
        // cout << i << " cyc " << cycles << endl;
        if (cycles & 1){

            ans ^= (arr[i] ^ xorval[i - 1] ^ xorval[n % i]);
            // cout << i << " " << arr[i] << " " << xorval[i-1] << " "<< xorval[n % i] << endl;
        }
        else {
            ans ^= (arr[i] ^ xorval[n % i]);
            // cout << i << " " << arr[i] << " " << xorval[n%i] << endl;
        }
        // cout << endl;

    }
    cout << ans << endl;
    return 0;
}