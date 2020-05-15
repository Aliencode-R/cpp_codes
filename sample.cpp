#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define ui unsigned int
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

void help(string str, ll Z[])
{
    ll n = str.size();
    ll L, R, k;

    L = R = 0;
    for (ll i = 1; i < n; ++i)
    {

        if (i > R)
        {
            L = R = i;

            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {

            k = i - L;

            if (Z[k] < R - i + 1)
                Z[i] = Z[k];

            else
            {

                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}
ll search(string str, string p)
{
    string concat = p + "&" + str;
    ll l = concat.size();

    ll Z[l];
    help(concat, Z);
    ll c = 0;
    for (ll i = 0; i < l; ++i)
    {

        if (Z[i] == p.size())
            c++;
    }
    // cout << c << concat << nL;

    return c;
}

vector<string> helper(string a1, string b1)
{
    vector<string> myvec;
    for (ll i = 1; i <= a1.size(); i++)
    {
        for (ll j = 0; j < b1.size(); j++)
        {
            string mystr = a1.substr(0, i) + b1.substr(j);
            // cout << mystr << nL;
            myvec.push_back(mystr);
        }
    }
    return myvec;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A >> B;
        ll n;
        cin >> n;
        vector<pair<string, ll>> si;
        for (ll i = 0; i < n; i++)
        {
            pair<string, ll> p;
            cin >> p.a;
            cin >> p.b;
            si.pb(p);
        }
        // for (int i = 0; i < n; i++){
        //     cout << si[i].a << si[i].b << nL;
        // }

        // logical string: a(0,e), b(s,n) ;)
        // get all possible logical strings
        vector<string> AB = helper(A, B);
        // I have ab, now check the ab for best ans
        ll ans = 0;
        for (auto i : AB)
        {
            ll this_ans = 0;
            for (auto j : si)
            {
                this_ans += (search(i, j.a) * j.b);
            }
            ans = max(ans, this_ans);
        }
        cout << ans << nL;
    }
    return 0;
}
