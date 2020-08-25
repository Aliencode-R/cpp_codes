#include <bits/stdc++.h>
#define forr(i, n) for (ll i = 0; i < n; i++)
#define ll long long int
#define oo 1000000000000000
using namespace std;
ll black[1100], white[1100];
ll dp[1100][2];
ll n, m, x, y;

ll get(ll i, ll c)
{
    if (i == m + 1)
        return 0;
    ll ans = INT_MAX;
    if (dp[i][c] != -1)
        return dp[i][c];
    for (ll j = i + x - 1; j <= m && j <= i + y - 1; j++)
    {
        if (c)
            ans = min(ans, white[j] - white[i - 1] + get(j + 1, c ^ 1));
        else
            ans = min(ans, black[j] - black[i - 1] + get(j + 1, c ^ 1));
    }
    return dp[i][c] = ans;
}

void _sol()
{
    cin >> n >> m >> x >> y;
    vector<string> t(n);
    forr(i, n) cin >> t[i];
    black[0] = 0, white[0] = 0;
    forr(i, m)
    {
        ll b = 0, w = 0;
        forr(j, n)
        {
            if (t[j][i] == '#')
                b++;
            else
                w++;
        }
        black[i + 1] = black[i] + b;
        white[i + 1] = white[i] + w;
    }
    memset(dp, -1, sizeof(dp));
    cout << min(get(1, 0), get(1, 1)) << endl;
    forr(i,m) cout <<black[i] << " " << white[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1; // cin >> t;
    while (t--)
        _sol();
}