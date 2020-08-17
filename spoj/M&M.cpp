#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map 
#define uset unordered_set 
#define MOD 1000000007
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
        int n; cin >> n;
        int arr[n];
        bool all1 = true;
        int xr = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(arr[i] != 1) all1 = false;
            xr = (xr^arr[i]);
        }
        if(all1) {
            cout << (n % 2 == 0 ? "John" : "Brother");
            cout << endl;
        }
        else {
            cout << (xr != 0 ? "John" : "Brother") << endl;
        }
    }

    return 0;
}    