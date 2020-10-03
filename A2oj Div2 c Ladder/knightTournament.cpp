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

const int N = 3e5 + 1;
int nx[N] = {};
int ans[N];


int get(int i)
{
    return nx[i] == i ? i : nx[i] = get(nx[i]);
}

void kil(int a, int b, int x)
{
    a = get(a);
    while (a <= b)
    {
        if (a != x)
        {
            ans[a] = x;
            nx[a] = a + 1;
        }
        else
        {
            a++;
        }
        a = get(a);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        nx[i] = i;
    }
    while(m--) {
        int l, r, x; cin >> l >> r >> x;
        kil(l,r,x);
        // int cur = get(l);

        // while(cur <= r) {
        //     if(cur == x) {
        //         cur++;
        //     } else {
        //         ans[cur] = x;
        //         nx[cur] = cur+1;
        //     }
        //     cur = get(cur);
        // }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " " ;
    }

    return 0;
}
