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
    int t ; cin >> t;
    while(t--) {
        int n; cin >> n;
        int x; cin >> x;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        int index = n-1;
        int dept = 0;
        while(index >= 0 and arr[index] >= x) {
            dept += (arr[index] - x);
            index--;
        }
        if(dept == 0) {
            cout << 0 << endl;
            continue;
        }
        int credit = 0;
        while(index >= 0 ) {
            credit += (x - arr[index]);
            index--;
        }
        if(dept == credit) {
            cout << 1 << " " << endl;
        } else {
            cout << 2 << " " <<  endl;
        }
        cout << dept << " " << credit << endl;

    }
    return 0;
}