#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a;
    int tmp = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                a.push_back(i);
            }
        }
    }
    if (n > 1)
        a.push_back(n);

    if (tmp == 1 || a.size() == 1)
        cout << "1\n0\n";
    else if (a.size() == 2)
        cout << "2\n";
    else
        cout << "1\n"
             << a[0] * a[1] << "\n";
}