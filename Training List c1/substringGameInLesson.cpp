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
    string s; cin >> s; 
    int n = s.size();
    string t(n, 'z');
    t[0] = s[0];
    // for(int i = 0; i < n; i++) t[i] = 'z';
    for(int i = 1; i < n; i++) {
        t[i] = min(s[i], t[i-1]);
    }
    cout << "Mike" << endl;
    for(int i = 1; i < n; i++) {
        if(t[i-1] < s[i]) {
            cout << "Ann" << endl;
        } else {
            cout << "Mike" << endl;
        }
    }
    return 0;
}