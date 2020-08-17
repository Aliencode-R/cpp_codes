#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100005;
int pr[N];
vector<int> primes;

// void seive() {
// 	primes.push_back(2);
// 	for(int i = 3; i < N; i+=2) {
// 		if(pr[i] == 0) {
// 			primes.push_back(i);
// 			for(int j = i*i; j < N; j+=i) {
// 				pr[j] = 1;
// 			}
// 		}
// 	}
// }

void seive()
{
    int i, j;
    for (i = 2; i < N; i++)
    {
        if (!pr[i])
        {
            primes.push_back(i);
            for (j = i; j < N; j += i)
            {
                pr[j]++;
            }
        }
    }
}

int32_t main()
{
    seive();

    // for(int i = 0; i < 100; i++)
    // {
    //     cout << primes[i] << endl;
    // }
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        bool seg[n - m + 1];
        memset(seg, false, sizeof(seg));

        for (auto x : primes)
        {
            if (x * x > n)
            {
                break;
            }

            int start = (m / x) * x;
            if (x >= m and x <= n)
            {
                start = x * 2;
            }

            for (int i = start; i <= n; i += x)
            {
                if (i >= m)
                {
                    seg[i - m] = 1;
                }
            }
        }
        for (int i = m; i <= n; i++)
        {
            if (seg[i - m] == 0 and i != 1)
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }

    return 0;
}