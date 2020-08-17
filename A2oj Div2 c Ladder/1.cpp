#include <bits/stdc++.h>

using namespace std;
bool possible(int m, int s)
{
    return (s >= 0) && (s <= 9 * m);
}

int main()
{
    int m, s, i, j, n, k = 0, sum;
    cin >> m >> s;
    sum = s;
    string min(""), max("");
    if ((s <= 0 && m > 1) || (s > 9 * m))
    {
        puts("-1 -1");
        return 0;
    }

    for (int pos = 0; pos < m; pos++)
    {
        for (int digit = 0; digit <= 9; digit++)
        {
            if ((pos > 0 || digit > 0 || (m == 1 && digit == 0)) && possible(m - pos - 1, sum - digit))
            {
                min += ('0' + digit);
                sum -= digit;
                break;
            }
        }
    }

    sum = s;
    for (int pos = 0; pos < m; pos++)
    {
        for (int digit = 9; digit >= 0; digit--)
        {
            if (possible(m - pos - 1, sum - digit))
            {
                max += ('0' + digit);
                sum -= digit;
                break;
            }
        }
    }

    cout << min << " " << max << endl;

    return 0;
}