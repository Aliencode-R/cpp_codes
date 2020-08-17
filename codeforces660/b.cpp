#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
 
    int test; cin >> test;
    while(test--) {
        int num; cin >> num;
        int ans = 6 + 10 + 14;
        if (ans >= num or num - ans == 6 or num - ans == 10 or num - ans == 14)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << 6 << " " << 10 << " " << 14 << " " << num - ans << endl;
        }
    }
    return 0;
}
