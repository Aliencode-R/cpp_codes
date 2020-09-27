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
    int tc; cin >> tc;
    while(tc--) {
        int n, t; cin >> n >> t; 
        int arr[n];
        umap<int,int> imap;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            // imap[arr[i]] ++;
        } 
        for(int i = 0; i < n; i++) {
            int cur = arr[i];
            if(2 * cur == t) {
                if(imap[cur] % 2 == 0) {
                    cout << 0 << " ";
                } else {
                    cout << 1 << " ";
                }
                imap[cur] ++;
            } else {
                // if(imap[t - cur] == 0) {
                    if(t-cur > cur) {
                        cout << 0 << " ";
                    } else {
                        cout << 1 << " ";
                    }
                    imap[cur]++;
            }
        }
        cout << endl;

    }
    return 0;
}