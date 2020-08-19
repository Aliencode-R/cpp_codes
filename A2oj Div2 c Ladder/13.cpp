#include <bits/stdc++.h>
using namespace std;
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
    int n, m; cin >> n >> m;
    string s[n];
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int count = 0;
    for(int i = 0; i < m; i++) {
        uset<char> st;
        for(int j = 0; j < n; j++) {
            // cout << s[j][i] << " ";
            st.insert(s[j][i]);
        }
        if(count == 0) {
            count = st.size();
        }
        else {
            count *= st.size();
        }
        // cout << st.size() << " ";
        count %= mod;
    }
    cout << count;
    return 0;
}