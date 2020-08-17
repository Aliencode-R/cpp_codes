#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dp[2002][2001];
    int n, h, l, r;
    cin >> n >> h >> l >> r;


    dp[0][0] = 0;

    for(int i = 1; i < h; i++) {
        dp[0][i] = -1;
    }
    int a[2001];
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {

        for(int hr = 0; hr < h; hr++) {
            dp[i+1][hr] = -1;
        }

        for(int hr = 0; hr < h; hr++) {
            if(dp[i][hr] == -1) {
                continue;
            }

            int h1 = (hr + a[i+1] - 1 + h) % h;
            int h2 = (hr + a[i+1]) % h;

            dp[i + 1][h1] = max(dp[i + 1][h1], dp[i][hr] + (l <= h1 and h1 <= r));
            dp[i + 1][h2] = max(dp[i + 1][h2], dp[i][hr] + (l <= h2 and h2 <= r));
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++) {
        ans = max(ans, dp[n][i]);
    }

    cout << ans << endl;

    return 0;
}
