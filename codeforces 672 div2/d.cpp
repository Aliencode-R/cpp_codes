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

struct item {
    int s;
    int e;
};

bool compare(item a, item b) {
    if(a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    item arr[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i].s >> arr[i].e;
    }
    sort(arr, arr + n, compare);

    int res = 0;
    for(int i = k - 1; i < n; i++) {
        int start = 0, end = i;
        int ans = i;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(arr[mid].e >= arr[i].s) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        if(i - ans +1 >= k) {
            res += i - ans + 2 - k;
        cout << i << " " << ans << endl;
        }

    }
    cout << res;

    return 0;
}