#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    char board[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> board[i][j];
        }
    }


    int ans = 0;
    for (int maskr = 0; maskr < (1 << h); maskr++)
    {
        for (int maskc = 0; maskc < (1 << w); maskc++)
        {
            int black = 0;
            for (int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++) {
                    if(((maskr>>i) & 1) == 0 and ((maskc>>j) & 1) == 0 and board[i][j] == '#') {
                        black ++;
                    }
                }
            }
            if(black == k) {
                ans ++;
            }
        }
    }
    cout << ans;
    // int maskc = (1<<w) - 1;

    // for ()

        return 0;
}
