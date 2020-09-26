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

bool compare(pii a, pii b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
bool compare2(pii a, pii b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; 
    vector<pii> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), compare);

    int ans = 0;
    int last = 1;
    for(int i = 1; i <n; i++) {
        if(v[i].first == v[i-1].first) {
            last++;
        } else {
            ans += (last * (last - 1)) / 2;
            last = 1;
        }
        if(i == n-1) {
            ans += (last * (last - 1)) / 2;
        }
    }
   

    sort(v.begin(), v.end(), compare2);

    last = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].second == v[i - 1].second)
        {
            last++;
        }
        else
        {
            ans += (last * (last - 1)) / 2;
            last = 1;
        }
        if (i == n - 1)
        {
            ans += (last * (last - 1)) / 2;
        }
    }
    pii p = {v[0].first, v[0].second};
    int pl = 1;
    int sub = 0;

    for(int i = 1; i < n; i++) {
        if(v[i].first == v[i-1].first and v[i].second == v[i-1].second) {
            pl++;
        } else {
            sub += (pl * (pl - 1) ) / 2;
            pl = 1;
        }
        if(i == n-1) {
            sub += (pl * (pl - 1)) / 2;
        }
    }
    // cout << sub << endl;
    cout << max(0ll, ans - sub);
    return 0;
}