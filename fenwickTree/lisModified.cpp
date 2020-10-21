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

int bit[199000] = {0};

void update(int i, int increment, int n)
{
    while (i <= n)
    {
        bit[i] = max(bit[i], increment);
        i += (i & (-i));
    }
    return;
}

int query(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans = max(ans, bit[i]);
        i -= (i & (-i));
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        memset(bit, 0, sizeof bit);
        int n; cin >>n;  
        int a[n+1]; 
        set<int> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }
        umap<int, int> imap;
        int ind = 1;
        for (auto x : s)
        {
            imap[x] = ind++;
        }

        for (int i = 1; i <= n; i++)
        {
            a[i] = imap[a[i]];

        }
        int w[n+1];
        for(int i = 1; i <= n; i++) cin >> w[i];
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int mx = query(a[i]-1);
            int f = mx + w[i];
            ans = max(ans, f);
            // w[i] = mx + w[i];
            update(a[i], f, n);
        }
        // for(int i = 1; i <= n; i++) {
        //     ans = max(ans, w[i]);
        // }
        cout << ans <<endl;
    }

    return 0;
}