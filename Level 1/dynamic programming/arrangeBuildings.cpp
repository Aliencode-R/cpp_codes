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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // same as count bin strings
    int n; cin >> n;
    int old0 = 1;
    int old1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int new0 = old1;
        int new1 = old1 + old0;

        old1 = new1;
        old0 = new0;
    }

    int t =  old0 + old1;
    cout << t * t;
    return 0;
}