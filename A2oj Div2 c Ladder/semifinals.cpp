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
    int n; cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    string s(n,'0');
    string t(n, '0');

    for(int k = 1; 2 * k <= n; k++) {
        s[k-1] = '1';
        t[k-1] = '1';
    }

    int i = 0, j = 0;
    for(int p = 0; p < n; p++) {
        if(a[i] <= b[j]) {
            s[i] = '1';
            i++;
        } else {
            t[j] = '1';
            j++;
        }
    }
    cout << s << endl << t;


    return 0;
}