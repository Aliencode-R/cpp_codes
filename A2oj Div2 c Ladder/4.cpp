#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int last = -1;
    for(int i = 0; i < n; i++) {
        if(last == -1) {
            last = min(v[i].first, v[i].second);
            continue;
        }
        if(last <= min(v[i].first,v[i].second)) {
            last = min(v[i].first, v[i].second);
        }
        else {
            last = max(v[i].first, v[i].second);
        }
    }
    cout << last;
    return 0;
}
