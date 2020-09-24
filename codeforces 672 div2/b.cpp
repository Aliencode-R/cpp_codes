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

int setBitNumber(int n)
{
    if (n == 0)
        return 0;

    int msb = 0;
    n = n / 2;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }

    return msb;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin>> n;
        int arr[n];
        int bits[63] = {};

        for(int i = 0; i<n; i++) {
            cin >> arr[i];
            int ind = setBitNumber(arr[i]);
            bits[ind] ++;
        }
        int ans = 0;
        for(int i = 0; i < 63; i++) {
            ans += (bits[i] * (bits[i] - 1) / 2);
        }
        cout << ans << endl;

    }
    return 0;
}