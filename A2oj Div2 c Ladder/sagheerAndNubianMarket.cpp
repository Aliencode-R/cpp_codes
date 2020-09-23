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

int isAllowed(int cur, int *arr, int s, int n) {
    int temp = 0;
    int brr[n];
    for(int i = 0; i < n; i++) {
        // temp += arr[i] + (i + 1) * cur;
        brr[i] = arr[i] + (i + 1) * cur;
    }
    sort(brr, brr+n);
    for(int i = 0; i < cur; i++) {
        temp += brr[i];
    }
    return temp;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s; cin >> n >> s;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    // sort(arr, arr+n);
    int start = 0, end = n;
    int ans = 0;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(isAllowed(mid, arr, s, n) <= s) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    int cost = isAllowed(ans, arr, s, n);
    cout << ans << " " << cost;
    return 0;
}