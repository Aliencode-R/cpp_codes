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
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        string s;
        cin >> s;
        int ans = -1;
        if(n % 2 == 1) {
            for(int i = 0; i < n; i+=2) {
                if(s[i] % 2 == 1) {
                    ans = 1;
                    break;
                }
            }
            if(ans == 1) {
                cout << ans << endl;
                continue;
            } else {
                cout << 2 << endl;
                continue;
            }
        }
        else {
            for(int i = 1; i < n; i+=2) {
                if(s[i] % 2 == 0) {
                    ans = 2;
                    break;
                }
            }
            if(ans == 2) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}