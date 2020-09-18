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
    int arr[n]; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxProfit = 0;
    int least = arr[0];
    int dpLeft[n];
    dpLeft[0] = 0;
    for(int i = 1; i < n; i++) {
        least = min(arr[i], least);

        dpLeft[i] = max(dpLeft[i-1], arr[i] - least);
    }

    int highest = arr[n-1];
    int dpRight[n];
    dpRight[n-1] = 0;
    for(int i = n-2; i >= 0; i--) {
        highest = max(arr[i], highest);

        dpRight[i] = max(dpRight[i+1], highest - arr[i]);    
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dpLeft[i] + dpRight[i]);
    }
    cout << ans;
    
    return 0;
}