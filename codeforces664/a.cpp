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

char swapIt(char &c) {
    if(c == '0') return '1';
    return '0';
}
// void swp(string s, int n) {
//     for(int i = 0; i <= n; i++) {
//         swapIt(s[i]);
//     }
// }
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        vector<int> v;
        int n; cin >> n;
        string s; cin >> s;
        string t; cin >> t;
        // cout << endl;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == t[i]) continue;

            if(s[0] != s[i]) {
                s[0] = swapIt(s[0]);
                v.push_back(1);
                // cout << s << endl;
            }
            // swp(s, i);
            for (int i1 = 0; i1 <= i; i1++)
            {
                s[i1] = swapIt(s[i1]);
            }
            reverse(s.begin(), s.begin() + i + 1);
            v.push_back(i+1);
            // cout << s << endl;
        }
        // cout << endl;
        cout << v.size() << " ";
        for(int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}