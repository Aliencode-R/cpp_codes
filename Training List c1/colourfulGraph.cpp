#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vl vector<ll>
#define pl pair<ll, ll>
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout << fixed << setprecision(10);
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pset;
const ll N = 1e5 + 3;
vector<set<ll>> G(N);
ll vis[N];

int main()
{
    fastIO
        ll n,
        m;
    cin >> n >> m;
    ll c[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> c[i];
        vis[c[i]] = 1;
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (c[x] != c[y])
        {
            G[c[x]].insert(c[y]);
            G[c[y]].insert(c[x]);
        }
    }
    //	for(ll i = 1; i <= n; i++)
    //	{
    //		for(auto j: G[i])
    //		{
    //			if(c[j] != c[i]) ++cnt[c[i]];
    //		}
    //	}
    ll mx = -1, ans = 1;
    for (ll i = 1; i < N; i++)
    {
        ll rowlen = G[i].size();
        if (rowlen > mx && vis[i])
        {
            mx = G[i].size();
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
