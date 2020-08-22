#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
   
    int test;
    cin >> test;
    while (test--)
    {
        int t0, t1, t2;
        cin >> t0 >> t1 >> t2;

        int p0, p1, p2;
        cin >> p0 >> p1 >> p2;
        int res = 0;
        int temp = min(t2, p1);
        t2 -= temp;
        p2 -= t0;
        p2 -= t2;
        if (p2 < 0)
        {
            p2 = 0;
        }
        res = 2 * (temp - min(p2, t1));
        cout << res << "\n";
    }
    return 0;
}