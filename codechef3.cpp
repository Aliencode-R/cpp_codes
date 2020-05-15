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
// #define vector <int> vi
#define all(x) (x).begin(), (x).end()
#define unordered_map umap
#define unoredered_set uset
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

class trip
{
public:
    int a, b, c;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // t = read(int);
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        // k = INT_MIN;

        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<trip> ans;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == i)
                continue;
            if ()
            {
                
            }
            trip v;
            v.a = i;
            v.b = arr[i];
            v.c = arr[arr[i]];
            swap(arr[arr[i]], arr[arr[arr[i]]]);
            swap(arr[i], arr[arr[i]]);
            ans.pb(v);
        }

        if ((int)ans.size() > k)
        {
            cout << -1 << endl;
            // cout << "now";
        }
        else
        {
            cout << (int)ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
            }
        }
    }
    return 0;
}
