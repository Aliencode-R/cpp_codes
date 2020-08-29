#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define PI (2 * acos(0.0))
#define eps 1e-9
#define pb push_back
#define endl "\n"
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define show(v)                           \
    for (int fi = 0; fi < v.size(); fi++) \
        cout << v[fi] << " ";             \
    cout << endl;
#define showpair(v)                       \
    for (int fi = 0; fi < v.size(); fi++) \
        cout << v[fi].first << " " << v[fi].second << endl;
#define ff first
#define ss second
#define fu cout << "lol" << endl;
#define precision(n) cout << fixed << setprecision(n);
#define lb lower_bound
#define up upper_bound
#define vscan               \
    for (i = 0; i < n; i++) \
    {                       \
        cin >> in;          \
        v.pb(in);           \
    }
#define all(a) a.begin(), a.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define mem(a, val) memset(a, val, sizeof(a))
#define loop(i, n) for (i = 0; i < n; i++)
#define TC()  \
    ull T;    \
    cin >> T; \
    while (T--)
#define IN(x)            \
    {                    \
        scanf("%d", &x); \
    }
#define LL(x)              \
    {                      \
        scanf("%lld", &x); \
    }
#define CC(x)            \
    {                    \
        scanf("%c", &x); \
    }
#define pfl(x) printf("%d\n", x)
#define pfll(x) printf("%lld\n", x)
#define newl puts("")
#define space printf(" ")
#define MOD 1000000007
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    int i = 0, j = 0, cs = 0, in;
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    vi v(n), sum(n);
    for (i = 0; i < n; i++)
        cin >> v[i];
    sum[0] = v[0];
    for (i = 1; i < n; i++)
        sum[i] = sum[i - 1] + v[i];
    ll ans = LLONG_MAX;
    for (i = 0; i <= n; i++)
    {
        ll cur = 0;
        if (i)
            cur += 1LL * sum[i - 1] * l;
        cur += 1LL * (sum[n - 1]) * r;
        if (i)
            cur -= 1LL * (sum[i - 1]) * r;
        cout << "** " << i << " " <<  cur << " "; 
        if (i < n - i)
            cur += 1LL * (n - 2 * i - 1) * qr;
        if (i > n - i)
            cur += 1LL * (2 * i - n - 1) * ql;
        cout << cur << endl;
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
