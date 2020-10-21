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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 10 * (n % 10 - 1);
        n /= (n % 10);
        if(n == 1) ans += 1;
        if(n == 11) ans += 3; 
        if(n == 111) ans += 6;
        if(n == 1111) ans += 10;
        cout << ans << endl;
    }
    return 0;
}