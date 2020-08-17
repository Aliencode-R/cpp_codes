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

bool isok(int *arr, int n, int maxTillNow) {

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >>n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start = 0, end = n;
        int ans;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(isok(arr, n, mid)) {
                ans = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}

