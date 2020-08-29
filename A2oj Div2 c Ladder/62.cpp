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
    int N = s.size();
    int n; cin >> n;
    umap<char,char> m;
    for(int i = 0; i < n; i++) {
        string a; cin >> a;
        char x = a[0];
        char y = a[1];
        m[x] = y;
        m[y] = x;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(m.count(s[i]) == 0) continue;
        char x = s[i];
        char y = m[s[i]]; 
        int c1 = 0;
        int c2 = 0;
        int j = i;
        while(j < N and (s[j] == x or s[j] == y)) {
            if(s[j] == x) c1++;
            if(s[j] == y) c2++;
            j++;
        }
        ans += min(c1, c2);
        i = j-1;
    }
    cout << ans;
    return 0;
}