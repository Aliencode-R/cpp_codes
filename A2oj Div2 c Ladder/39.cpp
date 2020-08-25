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
    // cout << __gcd(13,__gcd(14,12)) << endl;
    int n; cin >> n;
    if(n > 3) {
        if(n % 2 == 0) {
            if(n % 3 == 0) {
                cout << (n - 1) * (n - 2) * (n - 3);
            }
            else{
                cout << n*(n - 1) * (n - 3);
            }
        } 
        else
        cout << n * (n-1) * (n-2);
    }
    else {
        if(n == 3) cout << 6;
        if(n == 2) cout << 2; 
        if(n == 1) cout << 1;
        // cout << n ;
    }
    return 0;
}