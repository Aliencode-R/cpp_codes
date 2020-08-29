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
        string w; cin >> w;
        int n; cin >> n;
        int sn = w.size();
        string s(sn, '1');
        for(int i = 0;i < sn; i++) {
            if(w[i] == '0') {
                if(i-n >= 0) {
                    s[i-n] = '0';
                }
                if(i+n < sn) {
                    s[i+n] = '0';
                }
            }
        }
        bool flag = true;
        for(int i = 0; i < sn; i++) {
            bool one = false;
            one = one or (i - n >= 0 and s[i - n] == '1');
            one = one or (i + n < sn and s[i + n] == '1');

            if(w[i] != one + '0') {
                // cout << -1;
                flag = false;
                break;
            }
        }
        if(flag) cout << s << endl;
        else cout << -1 << endl;
    }
    return 0;
}