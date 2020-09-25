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

int sumd(int n) {
    int sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s; cin >> n >> s;
    int st = 0, e = n; 
    int ans = -1;
    while( st <= e ) {
        int mid = (st + e ) / 2;
        if(mid - sumd(mid) >= s) {
            ans = mid;
            e = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    if(ans == -1) cout << 0;
    else
    cout << n - ans + 1;
    return 0;
}