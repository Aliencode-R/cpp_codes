#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn], sum;
int n;
bool f(ll mid)
{
    for (int i = 0; i < n; i++)
    {
        if (mid < a[i])
            return 0;
    }
    return (n - 1) * mid >= sum;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll left = 0, right = 2e9 + 5, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (f(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << right << endl;
}