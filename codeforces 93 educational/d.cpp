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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        if(arr[0] + arr[1] <= arr[n-1]) {
            cout << 1 << " " << 2 << " " << n <<endl;
        }
        else {
            cout << -1 << endl;
        }
        // bool flag = false;
        // for(int i = 0; i < n-2; i++) {
        //     if(arr[i] + arr[i+1] > arr[i+2]) {
        //         cout << i << " " << i+1 << " " << i+2 << endl;
        //         flag = true;
        //         break;
        //     }
        // }
        // if(flag == false) cout << -1 << endl;
    }
    return 0;
}
