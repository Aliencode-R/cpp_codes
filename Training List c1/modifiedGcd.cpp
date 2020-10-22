#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

void findfactor(int n, vector<int> &v)
{
    v.push_back(1);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == (n / i))
            {
                v.push_back(i);
            }
            else
            {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        if (l == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

int helper(vector<int> v, int a, int b)
{
    int ans = -1;
    if (v[v.size() - 1] < a or v[0] > b)
    {
        return -1;
    }
    int start = 0, end = v.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] <= b and v[mid] >= a)
        {
            ans = v[mid];
            start = mid + 1;
        }
        else if (v[mid] < a)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

vector<int> merg(vector<int> &v1, vi &v2) {
    vi ans;
    for(int x : v1) {
        if(binary_search(v2.begin(), v2.end(), x)) {
            ans.push_back(x);
        }
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r;
    cin >> l >> r;
    if (__gcd(l, r) == 1)
    {
        solve();
        return 0;
    }
    vector<int> v;
    findfactor(l, v);
    v.push_back(l);
    sort(all(v));
    vector<int> v2;
    findfactor(r, v2);
    v2.push_back(r);
    sort(all(v2));

    vector<int> fin = merg(v, v2);
    // for(int i : fin) cout << i << endl;

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;

        cout << helper(fin, a, b) << endl;
    }

    return 0;
}