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
    int n; cin >> n;
    if(n == 0) {
        cout << 1 << " " << 1 << endl << 1 << endl;
    }
    else {
        cout << 3 << " " << 3 << endl;
        int allone = (1 << 18) - 1;
        int p17 = (1 << 17);
        cout << allone << " " << allone << " " << p17 << endl;
        cout << allone << " " << n << " " << p17 + n << endl;
        cout << p17 << " " << p17 + n << " " << n << endl;
    }
    return 0;
}