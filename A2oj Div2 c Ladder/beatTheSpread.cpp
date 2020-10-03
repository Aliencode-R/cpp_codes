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
        int s, d; cin >> s >> d;
        int a = (s + d) / 2;
        int b = s - a;
        if(b > a) swap(a, b);
        if(a >= 0 and b >= 0 and a + b == s and a - b == d) {
            cout << max(a,b) << " " << min(a,b) << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    return 0;
}