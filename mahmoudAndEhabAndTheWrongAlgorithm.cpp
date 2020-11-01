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
    if(n <= 5) {
        cout << -1 << endl;
    } else {
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 3 << endl;
        cout << 1 << " " << 5 << endl;
        cout << 2 << " " << 4 << endl;
        for(int i = 6; i <= n; i++) {
            cout << 2 << " " << i << endl;
        }
    }
    for(int i = 2; i <= n; i++) {
        cout << 1 << " " << i << endl;
    }
    return 0;
}