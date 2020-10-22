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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int ans = 0;
        int arr[k][26] = {0};
        for(int i = 0; i < k; i++) {
            umap<char, int> m;
            for(int j = i; j < n; j+=k) {
                // m[s[j]]++;
                arr[i][s[j] - 'a'] ++;
            }
            // int mx = -1;
            // for(auto p : m) {
            //     mx = max(mx, p.second);
            // }
            // cout << i << " " << mx<< endl;
            // ans += n/k - mx;
        }
        int i = 0, j = k-1;
        while(i <= j) {
            if(i == j) {
                int mx = -1;
                for(int q = 0; q < 26; q++) {
                    mx = max(mx, arr[i][q]);
                }
                ans += n/k - mx;
            } else {
                int mx = -1;
                for (int q = 0; q < 26; q++)
                {
                    mx = max(mx, arr[i][q] + arr[j][q]);
                }
                ans += 2 * (n / k) - mx;
            }
            i++, j--;
        }

        cout << ans << endl;
    }
    return 0;
}