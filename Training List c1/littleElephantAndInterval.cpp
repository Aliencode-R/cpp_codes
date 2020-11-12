#include <iostream>
using namespace std;
unsigned long long solve(unsigned long long x)
{
    unsigned long long ans = 0, f, e, xx = x;
    if (x < 10)
        return x;
    e = x % 10;
    while (x)
    {
        f = x % 10;
        x /= 10;
    }
    if (f <= e)
        ans = 9 + xx / 10;
    else
        ans = 8 + xx / 10;
    return ans;
}
int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}
