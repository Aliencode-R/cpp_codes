#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N), p, n;
    rep(i, N)
    {
        cin >> A[i];
        if (A[i] >= 0)
            p.push_back(A[i]);
        else
            n.push_back(A[i]);
    }

    int pn = p.size();
    int nn = n.size();
    bool ok = false;
    if (pn > 0)
    {
        if (N == K)
            ok = (nn % 2 == 0);
        else
            ok = true;
    }
    else
    {
        ok = (K % 2 == 0);
    }

    ll ans = 1;
    if (ok)
    {
        sort(p.begin(), p.end());
        sort(n.rbegin(), n.rend());
        if (K % 2 == 1)
        {
            ans *= p.back();
            p.pop_back();
        }
        vector<ll> t;
        while (p.size() >= 2)
        {
            ll x = p.back();
            p.pop_back();
            x *= p.back();
            p.pop_back();
            t.push_back(x);
        }
        while (n.size() >= 2)
        {
            ll x = n.back();
            n.pop_back();
            x *= n.back();
            n.pop_back();
            t.push_back(x);
        }
        sort(t.rbegin(), t.rend());
        rep(i, K / 2)
        {
            ans = ((ans % mod) * (t[i] % mod)) % mod;
        }
    }
    else
    {
        sort(A.begin(), A.end(), [](int x, int y) {
            return abs(x) < abs(y);
        });
        rep(i, K)
        {
            ans = (ans * A[i]) % mod;
            if (ans < 0)
                ans += mod;
        }
    }

    cout << ans << endl;
    return 0;
}
