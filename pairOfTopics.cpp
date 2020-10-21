#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<pair<int,int> , null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds;

// typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     pbds;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int a[n], b[n], c[n];

    for(int i = 0; i< n ; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++) c[i] = a[i] - b[i];

    pbds s;
    int count = 0;
    for(int i = 0; i < n; i++) {
        count += s.size() - s.order_of_key({-c[i], 1000000});
        s.insert({c[i], i});
    }
    cout << count ;

    return 0;
}