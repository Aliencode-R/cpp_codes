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
    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        v.push_back({num, i});
    }
    sort(v.begin(), v.end());
    vector<int> f, s;
    for(int i = 0; i < v.size(); i++) {
        if(i % 2 == 0) {
            f.push_back(v[i].second);
        } else {
            s.push_back(v[i].second);
        }
    }
    cout << f.size() << endl;
    for(auto x : f) 
        cout << x << " ";
    cout << endl;
    cout << s.size() << endl;
    for (auto x : s)
        cout << x << " ";
    cout << endl;

    return 0;
}