// Default template: @Aliencode-R
/*
*
 If I have seen further it is only by standing on the shoulders of giants.
*
*/
#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define x first
#define y second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unoredered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
void constructZ(string str, int *z)
{
    int len = str.size();
    int l, r, k;
    l = 0;
    r = 0;
    for (int i = 1; i < len; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < len && str[r - l] == str[r])
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else
        {
            k = i - l;

            if (z[k] <= r - i)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < len && str[r - l] == str[r])
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}
umap<ll, ll> imap;
class trip
{
public:
    ll a, b, c;
};
void fucku(ll* arr, ll n, vector<trip>& ret){
    for (ll first = 1; first <= n; first++)
    {
        // dont work if val = index :)
        if (arr[first] == first)
            continue;

        ll sec = imap[first];
        ll third = imap[sec];

        //count space between first and third
        int len = 0;
        for (int f = 0; f <= n; f++)
        {
            len++;
        }

        if (first == third) //12 21 wala case
        {
            continue;
        }
        
        if (third > n)
        {
            // isok = true;
            break;
        }
        trip mytrip;
        mytrip.a = first;
        mytrip.b = third;
        mytrip.c = sec;
        ret.push_back(mytrip);

        ll f = arr[first];
        ll s = arr[sec];
        ll t = arr[third];
        swap(arr[first], arr[sec]);
        swap(arr[sec], arr[third]);
        // if not found
        for (int r = 1; r <= n; r++)
        {
            len++;
        }
        // rightShift(arr[first],arr[sec],arr[third]);
        // rightShift(imap[f],imap[s],imap[t]);
        // for(int i = 1; i <= n; i++) cout << arr[i] << " ";
        // cout << nL;
        // 4 4 2 3 2 4 1 5 2 2 5 1 3 4 4 2 3 1 4 2 5 2 1 4 3 2 5
        // 1 1 3 4 2 1 4 3 2 5 4 - 1 - 1
        swap(imap[f], imap[s]);
        swap(imap[f], imap[t]);
    }
}
void zSearch(string text, string pattern)
{
    string concat = pattern + "$" + text;
    int len = concat.size();
    int z[len];
    constructZ(concat, z);

    for (int i = 1; i < len; i++)
    {
        if (z[i] == pattern.size())
        {
            cout << i - pattern.size() - 1 << " ";
        }
    }
}


void rightShift(ll &x, ll &y, ll &z)
{
    swap(x, y);
    swap(y, z);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        // k = INT_MIN;
        bool isok = false;
        ll arr[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            imap[arr[i]] = i;
        }
        vector<trip> ret;
        fucku(arr,n,ret);
        for (ll first = 1; first <= n; first++)
        {
            // dont work if val = index :)
            if (arr[first] == first)
                continue;

            ll sec = imap[first];
            ll third = imap[sec];

            //count space between first and third
            int len = 0;
            for (int f = 0; f <= n; f++)
            {
                len++;
            }

            if (first == third) //12 21 wala case
            {
                third = first + 1;
                if (third == sec)
                    third++;

                while (third <= n && third == arr[third])
                {
                    third++;
                    if (third > n) //or ret.size() < k+1)
                    {
                        break;
                    }
                    if (false or third == first or third == sec)
                    {
                        third++;
                    }
                    if (third != arr[third])
                    {
                        break;
                    }
                    // cout << len<<" "
                }
            }
            if (third > n)
            {
                isok = true;
                break;
            }
            trip mytrip;
            mytrip.a = first;
            mytrip.b = third;
            mytrip.c = sec;
            ret.push_back(mytrip);

            ll f = arr[first];
            ll s = arr[sec];
            ll t = arr[third];
            swap(arr[first], arr[sec]);
            swap(arr[sec], arr[third]);
            // if not found
            for (int r = 1; r <= n; r++)
            {
                len++;
            }
            // rightShift(arr[first],arr[sec],arr[third]);
            // rightShift(imap[f],imap[s],imap[t]);
            // for(int i = 1; i <= n; i++) cout << arr[i] << " ";
            // cout << nL;
            // 4 4 2 3 2 4 1 5 2 2 5 1 3 4 4 2 3 1 4 2 5 2 1 4 3 2 5
            // 1 1 3 4 2 1 4 3 2 5 4 - 1 - 1
            swap(imap[f], imap[s]);
            swap(imap[f], imap[t]);
        }
        if (isok == true)
        {

            cout << "-1" << nL;
            // cout << "error202";
        }
        else if ((int)ret.size() > k)
        {
            // cout << ret.size();
            // cout << k << " ";
            cout << -1 << endl;
            // cout << "now";
        }
        else
        {
            cout << (int)ret.size() << endl;
            for (int i = 0; i < ret.size(); i++)
            {
                cout << ret[i].a << " " << ret[i].b << " " << ret[i].c << endl;
            }
            // for(int i = 1; i <= n; i++) cout << arr[i] << " ";
        }
    }
    return 0;
}
