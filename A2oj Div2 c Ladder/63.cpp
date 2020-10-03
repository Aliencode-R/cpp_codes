#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define Rep(i, a, b) for (int i = a; i <= b; ++i)
#define Rrep(i, a, b) for (int i = a; i > b; --i)
#define rrep(i, a, b) for (int i = a; i >= b; --i)
#define sq(a) (a) * (a)
#define nitro std::ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug(x) std::cerr << #x << "=" << x << '\n'
#define text std::cerr << "SacredCoupoid08\n"
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define U 1000000007
#define N 100005
#define sz(c) (int)c.size()
#define pb push_back
#define pv(x)             \
    for (auto y : x)      \
        cout << y << " "; \
    cout << '\n';
#define fr first
#define sc second
#define ppb pop_back
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define int ll
#define tr(c, it) for (typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ri(X) scanf("%lld", &(X))
#define rii(X, Y) scanf("%lld%lld", &(X), &(Y))
#define riii(X, Y, Z) scanf("%lld%lld%lld", &(X), &(Y), &(Z))
#define dri(X) \
    ll(X);     \
    scanf("%lld", &X)
#define drii(X, Y) \
    ll X, Y;       \
    scanf("%lld%lld", &X, &Y)
#define driii(X, Y, Z) \
    int X, Y, Z;       \
    scanf("%lld%lld%lld", &X, &Y, &Z)
#define rs(X) scanf("%s", (X))
typedef long long ll;
typedef std::vector<ll> vi;
typedef std::pair<ll, ll> pi;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     pbds;
const double pie = 3.14159265358979323846;

long long calc(long long a)
{
    if (a < 10)
        return a;
    long long r = a / 10;
    r += 8;
    long long f = a;
    while (f >= 10)
        f /= 10;
    if (f <= a % 10)
        r++;
    return r;
}
signed main()
{
    nitro;
    int CASE = 1;
    //ri (CASE);
    //cin>>CASE;
    while (CASE--)
    {
        int a, b;
        cin >> a >> b;
        cout << calc(b) - calc(a - 1) << endl;
    }

    return 0;
}
