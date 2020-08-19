#include <bits/stdc++.h>
using namespace std;
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
    int n; cin >> n;
    int c4 = 0;
    int c7 = 0;
    // if(n == 4) {
    //     cout << 4 ;
    //     return 0;
    // }
    while(n > 0) {
        if(n % 7 == 0) {
            c7 = n / 7;
            break;
        }
        c4++;
        n -= 4;
    }
    if(c7 == 0 and n != 0) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < c4; i++) {
        cout << 4;
    }
    while(c7--) cout << 7;
    return 0;
}