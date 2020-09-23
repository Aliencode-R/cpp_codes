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
    int n, m; cin >> n >> m;
    int left[n], right[n];
    memset(left, m+1, sizeof left);
    memset(right, 0, sizeof right);
    int maxFloor = -1;
    for(int i = n-1; i >= 0; i--) {
        string s; cin >> s;
        for(int j = 0; j < m+2; j++) {
            if(s[j] == '1') {
                right[i] = j;
                if(maxFloor == -1) maxFloor = i;
            }
        }
        for(int j = m+1; j >= 0; j--) {
            if(s[j] == '1') {
                left[i] = j;
            }
        }
    }

    int ans = imax;
    for(int stairs = 0; stairs < (1 << n - 1); stairs++) {
        int cur = 0, room = 0, floor = 0;

        while(floor <= maxFloor) {
            if(room == 0) {
                cur += right[floor];
                room = right[floor];
            } else {
                cur += room - left[floor];
                room = left[floor];
            }
            if(floor == maxFloor) break;
            int nxt = (stairs & (1 << floor)) == 0 ? 0 : m+1;
            cur += abs(nxt - room) + 1;

            room = nxt;
            floor++;

        }

        ans = min(ans, cur);

    }
    cout << ans;
    return 0;
}