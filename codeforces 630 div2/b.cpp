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
        int arr[n];
        for(int i = 0; i <n; i++) cin >> arr[i];
        int p[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int brr[n];
        umap<int,int> m;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= 11; j++) {
                if(arr[i] % p[j] == 0) {
                    brr[i] = j;
                    ans = max(ans, j);
                    m[j]++;
                    // continue;
                    break;
                }
            }
        }
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            // cin >> arr[i];
            s.insert(brr[i]);
            // mx = max(mx, arr[i]);
        }
        ans = s.size();
        // cordinate compression
        umap<int, int> imap;
        int ind = 1;
        for (auto x : s)
        {
            imap[x] = ind++;
        }

        for (int i = 0; i < n; i++)
        {
            brr[i] = imap[brr[i]];
        }
        // for(int i = 1; i <= ans; i++) {
        //     if(m.count(i)== 0) {
        //         for(int j = 0; j < n; j++) {
        //             if(m[brr[j]] > 1) {
        //                 m[brr[j]] --;
        //                 brr[j] = i;
        //             }
        //         }
        //     }
        // }
        cout << ans << endl;
        for(int x : brr) cout << x << " ";
        cout << endl;
    }
    return 0;
}