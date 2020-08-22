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
        int n; cin >> n; 
        int arr[n]; 
        int brr[n];
        int x = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            brr[i] = arr[i];
            x = min(x, arr[i]);
        }
        sort(brr, brr+n);
        bool flag = false;
        for(int i = 0; i < n;i++) {
            if(arr[i] == brr[i]) {
                continue;
            }
            if(arr[i] != brr[i] and arr[i] >= x and arr[i] % x == 0) {
                continue;
            }
            else {
                flag = true;
                break;
            }
        }
        if(flag == false) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}