#include <bits/stdc++.h>
using namespace std;
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
#define endl "\n"

// bool compare(pii a, pii b) {
    
//     return abs(a.first) < abs(b.first) or abs(a.second) < abs(b.second);
// }
 bool compare(pii a, pii b)
{

        return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n;
        cin >> n;
        vector<pii> v(n);
        int ans = 6 * n;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
            if (v[i].first == 0 or v[i].second == 0)
            {
                ans -= 2;
            }
        }
        cout << ans << endl;
        sort(v.begin(), v.end(), compare);
        
        for (int i = 0; i < n; i++)
        {
            // go to x
            int x = v[i].first;
            int y = v[i].second;
            if (x > 0)
            {
                cout << 1 << " " << x << " R" << endl;
            }
            if (x < 0)
            {
                cout << 1 << " " << -x << " L" << endl;
            }
            if (y > 0)
            {
                cout << 1 << " " << y << " U" << endl;
            }
            if (y < 0)
            {
                cout << 1 << " " << -y << " D" << endl;
            }
            // pick it
            cout << 2 << endl;

            // now go back
            if (x > 0)
            {
                cout << 1 << " " << x << " L" << endl;
            }
            if (x < 0)
            {
                cout << 1 << " " << -x << " R" << endl;
            }
            if (y > 0)
            {
                cout << 1 << " " << y << " D" << endl;
            }
            if (y < 0)
            {
                cout << 1 << " " << -y << " U" << endl;
            }
            // diffuse it
            cout << 3 << endl;
        }
        return 0;
    }