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
const int N = 10000000;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int arr[n];
    int total = 0;
    int mx = imin;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
        mx = max(arr[i], mx);
    }
    sort(arr, arr+n);
    int ans = abs(n - total);
    // int index;
    // cout << N/n;
    int end = total - n;
    for(int i = 2; pow(i, n-1) <= end + mx; i++) {
        int temp = 0;
        for(int j = 0; j < n; j++) {
            temp += abs(pow(i,j) - arr[j]);
        }
        ans = min(ans, temp);
        
        // if(last < ans)break;
        // last = ans;
    }
    cout << ans;
    return 0;
}