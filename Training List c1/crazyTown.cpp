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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n; cin >> n; 
    int ans = 0;
    for(int i = 0; i< n; i++) {
        int a, b, c; cin >> a >> b >> c;
        int pol = a * x1 + b * y1 + c;
        int pol2 = a * x2 + b * y2 + c;

        if((pol > 0 and pol2 < 0) or (pol < 0 and pol2 > 0)) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}