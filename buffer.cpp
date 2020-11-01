/*
Just Another Source code by -
Ambuj              
*/
#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define vl vector<ll>
#define vvi vector<vector<ll>>
#define pii pair<int, int>
#define VP vector<pii>
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (long(i) = (a); (i) < (b); (i)++)
#define all(v) (v).begin(), (v).end()
#define S(x) scanf("%d", &(x))
#define S2(x, y) scanf("%d%d", &(x), &(y))
#define SL(x) scanf("%lld", &(x))
#define SL2(x) scanf("%lld%lld", &(x), &(y))
#define P(x) printf("%d\n", (x))
#define FF first
#define SS second
#define teji                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define DI \
    int n; \
    cin >> n;
using namespace std;
bool desc(int a, int b)
{
    return a > b;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int a[101010], g[101010], vis[101010];
vector<int> v;
vvi adj(101010, vi());
void dfs(int u, int ec, int oc, int level)
{

    if (level % 2 == 0)
        a[u] = (a[u] + ec) % 2;
    else
        a[u] = (a[u] + oc) % 2;

    if (a[u] != g[u])
    {
        v.pb(u);

        if (level % 2 == 0)
            ec++;
        else
            oc++;
    }
    vis[u] = 1;
    rep(i, 0, adj[u].size())
    {
        int child = adj[u][i];
        if (!vis[child])
        {
            dfs(child, ec, oc, level + 1);
        }
    }
    if (a[u] != g[u])
    {
        if (level % 2 == 0)
            ec--;
        else
            oc--;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/ambuj/.config/sublime-text-3/Packages/User/input.txt", "r", stdin);
    freopen("/home/ambuj/.config/sublime-text-3/Packages/User/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    rep(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> g[i];
    dfs(1, 0, 0, 0);
    cout << v.size() << endl;
    rep(i, 0, v.size()) cout << v[i] << endl;
    return 0;
}