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

vector<char> ans;

void print(char c, int n) {
    while(n--) ans.push_back(c);
}

struct cell {
    int x;
    int y;
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    cell from[k+1], to[k+1];

    for(int i = 1; i <= k; i++) 
    {
        cin >> from[i].x >> from[i].y;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> to[i].x >> to[i].y;
    }

    cell pending;
    pending.x = pending.y = 0;
    
    // int steps = 0;
    for(int i = 1; i <= k; i++) {

        from[i].x += pending.x;
        from[i].y += pending.y;

        from[i].x = min(from[i].x, n);
        from[i].x = max(from[i].x, 1ll);

        from[i].y = min(from[i].y, m);
        from[i].y = max(from[i].y, 1ll);

        if(to[i].x > from[i].x) {
            print('D', to[i].x - from[i].x);
            pending.x += to[i].x - from[i].x;
        }
        if (to[i].x < from[i].x)
        {
            print('U', from[i].x - to[i].x );
            pending.x += to[i].x - from[i].x;
        }
        if (to[i].y > from[i].y)
        {
            print('R', to[i].y - from[i].y);
            pending.y += to[i].y - from[i].y;
        }
        if (to[i].y < from[i].y)
        {
            print('L', from[i].y - to[i].y);
            pending.y += to[i].y - from[i].y;
        }
    }
    if(ans.size() <= 2 * n * m) {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) cout << ans[i];
    } else {
        cout << -1;
    }


    return 0;
}