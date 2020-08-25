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
    int n, k; cin >> n >> k;
    int arr[n];
    cin >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        // arr[i] += arr[i-1];
        // cout << arr[i] << " ";
    }
    sort(arr, arr+n);
    for(int i = 1; i < n; i++) {
        arr[i] += arr[i-1];
        // cout << arr[i] << " ";
    }
    if(n == 1) {
        cout << 1 << " ";
        cout << arr[0];
        return 0;
    }
    pair<int,int> res;
    res.first = INT_MIN;
    for(int i = 1; i < n; i++) {
        int width = i;
        int a = arr[i] - arr[i-1];
        int start = 0, end = width;
        int ans;
        while(start <= end) {
            int cnt = (start + end) / 2;
            int minus = (i - cnt - 1 >= 0) ? arr[i - cnt - 1] : 0 ;
            if (cnt * a - arr[i - 1] + minus <= k)
            {
                ans = cnt+1;
                start = cnt + 1;
                // cout << a << " " << ans << " " << arr[i-1] << " " << minus << endl;
            }
            else {
                end = cnt - 1;
            }
        }
        if(ans > res.first) {
            res.first = ans;
            res.second = a;
        }
    }
    // cout << endl;
    cout << res.first << " " << res.second;
    return 0;
}