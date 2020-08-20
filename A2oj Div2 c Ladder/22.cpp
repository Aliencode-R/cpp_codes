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
    vector<int> v(n) , a(n);
    for(int i = 0;i < n; i++) {
        cin >> v[i];
        a[i] = v[i];
    }
    sort(v.begin(), v.end()) ;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != v[i]) {
            // cout << a[i] << " " << v[i] << endl;
            count++;
        }
    }
    // cout << count;
    if(count <= 2) cout << "YES";
    else cout << "NO";
    return 0;
}