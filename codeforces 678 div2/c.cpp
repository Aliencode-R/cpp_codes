#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
using ll = long long;
ll fact[1004];

ll power(ll x, ll y, ll p)
{
    ll res = 1;

    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

ll nCr(ll n, ll r, ll p)
{

    if (r == 0 || n == 0)
        return 1;

    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}
int main()
{
    ll n, x, pos;
    cin >> n >> x >> pos;

    fact[0] = 1;
    for (ll i = 1; i < 1004; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    ll arr[n + 1];
    for (ll i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    ll l = 0, g = 0, s = 0, r = n;

    while (l < r)
    {
        ll mid = (l + r) / 2;

        if (arr[mid] <= pos)
        {
            l = mid + 1;
            s++;
        }
        else
        {
            r = mid;
            g++;
        }

        //if(l>0 and arr[l-1]==pos)break;else
    }
    s--;
    //cout<<g<<" "<<s<<endl;
    ll tg = n - x, ts = x - 1, ans = 0;

    if (g <= tg && s <= ts)
    {
        ans = (((nCr(tg, g, mod) * fact[n - (g + s) - 1]) % mod) * nCr(ts, s, mod)) % mod;
        ans = ans * fact[g];
        ans %= mod;
        ans = ans * fact[s];
        ans %= mod;
    }
    cerr << "hello";
    cout << ans << endl;
    return 0;
}