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
        int a, b, c, d; cin >> a >> b >>c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        x += b - a;
        y += d - c;
        // cout << x << "    " << y << endl;
        if(x <= x2 and x >= x1 and y >= y1 and y <= y2) {
            if(x1 == x2 and (a != 0 or b != 0)) {
                cout << "No" << endl;
            } else if(y1 == y2 and (c != 0 or d != 0)) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;

            }
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}