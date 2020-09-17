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

struct item {
    double val;
    double wt;
};

bool compare(item a, item b) {
    return a.val/a.wt > b.val/b.wt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<item> v(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> v[i].val;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].wt;
    }
    double amt; cin >> amt;
    sort(v.begin(), v.end(), compare);
    // for(auto x : v) cout << x.val << " ";
    // double ans = 0;
    // int w = 0;
    // for(int i = 0; i < n; i++) {
    //     if(w + v[i].wt <= amt) {
    //         ans += v[i].val;
    //         w += v[i].wt;
    //     } else {
    //         int remain = amt - w;
    //         ans += v[i].val * ((double)remain / v[i].wt);
    //         break;
    //     }
    // }
    double vib = 0;
    int rc = amt;

    int i = 0;
    while (i < n)
    {
        if (v[i].wt <= rc)
        {
            vib += v[i].val;
            rc -= v[i].wt;
        }
        else
        {
            vib += v[i].val * rc / v[i].wt;
            rc = 0;
            break;
        }

        i++;
    }
    cout << vib;

    return 0;
}