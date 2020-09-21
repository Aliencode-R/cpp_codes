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

unsigned getNthUglyNo(unsigned n)
{
    unsigned ugly[10001]; // To store ugly numbers
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;

    ugly[0] = 1;
    for (int i = 1; i < n; i++)
    {
        next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                               next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2 + 1;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3 + 1;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5 = i5 + 1;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // unsigned arr[10001] = getNthUglyNo(10001);
    // for(int x: v) cout << x << " ";
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << getNthUglyNo(n) << endl;
    }
    return 0;
}