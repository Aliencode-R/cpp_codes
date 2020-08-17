#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<ll, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

bool helper1(ll a, ll b, ll c, ll na, ll nb, ll nc)
{

    // case 1
    if (b != 0 and nb % b == 0)
    {
        ll m = nb / b;
        ll x = nc - c;
        // cout << m << x << endl;
        if (m * (a + x) == na and c + x == nc and m * b == nb)
        {
            return true;
        }
    }
    // cout << "pop";
    // case 2
    if (b != 0 and nb % b == 0)
    {
        ll m = nb / b;
        if (a != 0 and c != 0 and
            na % a == 0 and nc % c == 0 and
            na / a == m and nc / c == m and
            na / a - a == nc / c - c and m * b == nb)
        {
            return true;
        }
    }

    // case 3 and 4 handled together
    // first find x and m from A and B
    // cout << "pop out  ";
    // cout << (b * na - a * nb) << "    " << "    " << (nb - na) << "    "  << (b * na - a * nb) / (nb - na) << endl;
    // cout << "(a * (nb - na))" << (a * (nb - na)) << endl;
    if ((nb - na) != 0 and (b * na - a * nb) % (nb - na) == 0 and
        (b * na - a * na) != 0 and (na * (nb - na)) % (b * na - a * na) == 0)
    {
        // cout << "pop in";
        ll x = (b * na - a * nb) / (nb - na);
        ll m = (na * (nb - na)) / (b * na - a * na);

        // case 3 >>>
        if (nc == c + x and m * (a + x) == na and m * (c + x) == nc) // TODO: EXTRA CONDITIONS HERE!
        {
            return true;
        }

        // case 4 >>>>
        if (nc == m * (c + x) and na == m * (a + x) and nb == m * (b + x))
        {
            return true;
        }
    }
    // cout << "poph1";
    //if we reached here helper 1 was not so helpful after all lets go to helper 2 |
    return false;
}

bool helper2(ll a, ll b, ll c, ll na, ll nb, ll nc)
{

    // case 1
    if (b != 0 and nb % b == 0)
    {
        ll m = nb / b;
        ll x = nc - c;

        if (m * a + x == na and c + x == nc and m * b == nb)
        {
            return true;
        }
    }
    // cout << "pop" ;
    // case 2
    if (b != 0 and nb % b == 0)
    {
        ll m = nb / b;
        if (na - m * a == nc - m * c)
        {
            return true;
        }
    }

    // case 3 and 4 handled together

    if ((a - b) != 0 and (a * nb - b * na) % (a - b) == 0 and (na - nb) % (a - b) == 0)
    {

        ll x = (a * nb - b * na) / (a - b);
        ll m = (na - nb) / (a - b);

        // case 3
        if (nc == c + x)
        {
            return true;
        }

        // case 4
        if (nc == m * c + x)
        {
            return true;
        }
    }

    //if we reached here helper 2 was not so helpful after all like helper 2
    return false;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, na, nb, nc;
        cin >> a >> b >> c >> na >> nb >> nc;
        ll da = na - a;
        ll db = nb - b;
        ll dc = nc - c;

        // cout << "pop1";
        // already set
        if (da == 0 and db == 0 and dc == 0)
        {
            cout << 0 << endl;
            continue;
        }

        // 1 op -> 3 set
        // cout << "pop2";
        if ((da == db and db == dc) or (da == db and dc == 0)                            // 1 equal
            or (db == dc and da == 0) or (da == dc and db == 0) or (da == 0 and db == 0) // 2 equal
            or (db == 0 and dc == 0) or (dc == 0 and da == 0))
        {

            cout << 1 << endl;
            continue;
        }
        // cout << "pop3";
        if ((a != 0 and b != 0 and c != 0 and nc % c == 0 and nb % b == 0 and na % a == 0 and na / a == nb / b and nb / b == nc / c) or
            (a != 0 and b != 0 and na % a == 0 and nb % b == 0 and na / a == nb / b and nc == c) or
            (a != 0 and c != 0 and na % a == 0 and nc % c == 0 and na / a == nc / c and nb == b) or
            (b != 0 and c != 0 and nc % c == 0 and nb % b == 0 and nb / b == nc / c and na == a))
        {

            cout << 1 << endl;
            continue;
        }
        // cout << "pop4";
        // 1 op -> 2 set

        if (da == db or db == dc or da == dc)
        {
            cout << 2 << endl;
            continue;
        }
        // cout << "pop4.3" ;
        if ((da != db and dc == 0) or (dc != db and da == 0) or (da != dc and db == 0))
        {
            cout << 2 << endl;
            continue;
        }
        // cout << "pop7";
        if ((a != 0 and b != 0 and na % a == 0 and nb % b == 0 and na / a == nb / b) or
            (c != 0 and b != 0 and nc % c == 0 and nb % b == 0 and nb / b == nc / c) or
            (a != 0 and c != 0 and na % a == 0 and nc % c == 0 and na / a == nc / c))
        {
            cout << 2 << endl;
            continue;
        }
        // cout << "pop5";
        if (helper1(a, b, c, na, nb, nc) or
            helper1(a, c, b, na, nc, nb) or
            helper1(b, a, c, nb, na, nc) or
            helper1(b, c, a, nb, nc, na) or
            helper1(c, a, b, nc, na, nb) or
            helper1(c, b, a, nc, nb, na))
        {
            cout << 2 << endl;
            continue;
        }
        // cout << "pop6";
        if (helper2(a, b, c, na, nb, nc) or
            helper2(a, c, b, na, nc, nb) or
            helper2(b, a, c, nb, na, nc) or
            helper2(b, c, a, nb, nc, na) or
            helper2(c, a, b, nc, na, nb) or
            helper2(c, b, a, nc, nb, na))
        {
            cout << 2 << endl;
            continue;
        }

        // cout << "here " << helper1(7,11,9,50,70,12) << endl;

        //	3 op -> 3 set
        cout << 3 << endl;
    }
    return 0;
}
