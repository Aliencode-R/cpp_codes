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

int helper(int a, int b, int x, int y, int n) {
    int temp = n;
    int a1 = max(a-n, x);
    n -= (a-a1);
    int b1 = max(b-n, y);
    return a1*b1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        cout << min(helper(a,b,x,y,n), helper(b,a,y,x,n)) << endl;
    }
    return 0;
}