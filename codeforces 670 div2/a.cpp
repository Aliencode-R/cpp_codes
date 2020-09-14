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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int,int> m;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            m[a]++;
        }
        int x = 0, y = 0;
        for(int i = 0; i < 101; i++) {
            if(m[i] >= 1) {
                x++;
                m[i]--;
            } else {
                break;
            }
        }
        for (int i = 0; i < 101; i++)
        {
            if (m[i] >= 1)
            {
                y++;
                m[i]--;
            }
            else
            {
                break;
            }
        }
        // for(auto p : m){
        //     if(p.second >= 1) {
        //        x++;
        //        m[p.first]--; 
        //     }
        //     else {
        //         break;
        //     }
        // }
        // for (auto p : m)
        // {
        //     if (p.second >= 1)
        //     {
        //         y++;
        //         // cout << m[p.first] << " ";
        //         // cout << endl;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        cout << x + y << endl;
    }
    return 0;
}