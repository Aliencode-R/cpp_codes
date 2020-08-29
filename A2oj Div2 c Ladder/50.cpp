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
    int a; cin >> a;
    string s; cin >> s;
  
    umap<int,int> m;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += s[j] - '0';
            m[sum]++;
        }
    }
    if (a == 0)
    {
        int ans = 0;
        for(auto p : m) {
            ans += p.second*m[0];
        }
        cout << ans*2 - m[0]*m[0];
        return 0;        
    }
    // for(auto p : m) {
    //     cout << p.first << " " << p.second << endl;
    // }
    int ans = 0;
    for(auto p : m) {
        int x = p.first;
        if(x == 0) continue;
        int y = a / x;
        if(y * x != a) continue;
        int f1 = p.second;
        int f2 = m[y];
        ans += (f1 * f2);
    }
    cout << ans;

    return 0;
}