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
    int test; cin >> test;
    for(int t = 1; t <= test; t++) {
        int n; cin >> n;
        int arr[n];
        for(int i= 0; i < n; i++) {
            cin >> arr[i];
        }
        int last = arr[1] - arr[0];
        int ans = 2;
        int temp = 2;
        for(int i = 2; i < n; i++) {
            if(arr[i] - arr[i-1] == last) {
                temp++;
            }
            else {
                last = arr[i] - arr[i-1];
                temp = 2;
            }
            ans = max(ans, temp);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}