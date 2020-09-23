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
    int arr[n] ;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int ans = arr[1] - arr[0];

    for(int i = 2; i < n; i++) {
        int temp = ans;
        int p = arr[i] - arr[i-1];
        p *= (pow(2, i-1) - 1);
        temp = 2 * (ans + p) + arr[i] - arr[i-1];
        ans += temp;
        ans %= mod;
    }

    cout << ans;

    return 0;
}