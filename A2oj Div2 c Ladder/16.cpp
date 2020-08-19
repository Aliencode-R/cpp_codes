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
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    if(n == 1) {
        cout << -1 ;
        return 0;
    }
    if(arr[0] == arr[n-1]) {
        cout << 1 << endl;
        cout << arr[0] << " ";
        return 0;
    }
    // bool r = true;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            cout << 0;
            return 0;
        }
    }
 
    if(n == 2) {
        int d = arr[1] - arr[0];
        if(d % 2 != 0) {
            cout << 2 << endl;
            cout << arr[0] - d << " " << arr[1] + d;
            return 0;
        }
        set<int> s;
        s.insert(arr[0] + d / 2);
        s.insert(arr[0] - d);
        s.insert(arr[1] + d);
        cout << 3 << endl;
        for(auto x : s) cout << x << " " ;
        return 0;
    }

    // check if ap
    int d = min(arr[1] - arr[0], arr[2] - arr[1]);
    bool ap = true;
    int count = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] - arr[i-1] != d) {
            ap = false;
            count++;
        }
    }
    if(ap) {
        cout << 2 << endl;
        cout << arr[0] - d << " " << arr[n-1] + d;
        return 0;
    }
    else {
        if(count > 1) {
            cout << 0 ;
            return 0;
        }
        // int d2 = arr[2] - arr[1];
        // d = min(d, d2);
        // cout << arr[3] - arr[2] << " " << d << endl;
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i-1] == 2 * d) {
                cout << 1 << endl;
                cout << arr[i-1] + d ;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}