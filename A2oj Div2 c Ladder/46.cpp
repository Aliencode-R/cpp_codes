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
    int n, l, r, ql, qr; 
    cin >> n >> l >> r >> ql >> qr;
    int arr[n];
    for(int i = 0; i < n;i++ ) {
        cin >> arr[i];
    }
    int lsum[n], rsum[n+1];
    lsum[0] = arr[0];
    rsum[n-1] = arr[n-1];
    rsum[n] = 0;
    for(int i = 1; i < n; i++) {
        lsum[i] = arr[i] + lsum[i-1];
    }
    for(int i = n-2; i >= 0; i--) {
        rsum[i] = arr[i] + rsum[i+1];
    }
    int ans = INT_MAX;
    for(int i = 0; i <= n; i++) {
        int cur = lsum[i] * l + rsum[i+1] * r;
        // if(i == 1) {
            cout <<"1  " <<  cur << " ";
        // }
            if (i)
                cur -= 1LL * (lsum[i - 1]) * r;
            if (i > n - i)
                cur += (2 * (i)-n - 1ll) * ql;
            if (i < n - i)
                cur += (n - 2 * (i)-1ll) * qr;
            // if (i == 1)
            // {
            cout << "2  " << cur << endl;
        // }
        ans = min(ans, cur);
        cout << i << " " << ans << " " <<  cur << endl;
    }
    cout << ans;
    return 0;
}