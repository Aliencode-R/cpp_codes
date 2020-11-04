
#include <bits/stdc++.h>


using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define int long long
// int arr[11][100];
// pii dp[11][100];
// int n, m; 


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; 
    while(cin >> n >> m) {
        int arr[n][m];
        pii dp[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> arr[i][j];
                dp[i][j] = {imax, i};
            }
        }

        for(int i = 0; i < n; i++) {
            dp[i][m-1] = {arr[i][m-1], -1};
        }
    
        for(int j = m-2; j >= 0; j --) {
            for(int i = 0; i < n; i++) {
                int i1, i2, i3;
                if(i == 0) {
                    i1 = i;
                    i2 = (i+1)%n;
                    i3 = (i - 1 + n) % n;
                    
                } else if(i == n-1) {
                    i1 = (i + 1) % n;
                    i2 = (i - 1 + n) % n;
                    i3 = i;
                } else {
                    i1 = (i - 1 + n) % n;
                    i2 = i;
                    i3 = (i + 1) % n;
                }
                int sum = imax, nextI = -1;
                if(dp[i1][j+1].first < sum) {
                    sum = dp[i1][j+1].first;
                    nextI = i1;
                }
                if (dp[i2][j + 1].first < sum)
                {
                    sum = dp[i2][j + 1].first;
                    nextI = i2;
                }
                if (dp[i3][j + 1].first < sum)
                {
                    sum = dp[i3][j + 1].first;
                    nextI = i3;
                }
                dp[i][j] = {sum + arr[i][j], nextI};
            }
        }

        int minI;
        int lsum = imax;
        for(int i = 0; i < n; i++) {
            if(dp[i][0].first < lsum) {
                minI = i;
                lsum = dp[i][0].first;
            }
        }
        int sum = 0;
        int j = 0; 
        // cout << endl;


        while(j < m) {
            cout << minI + 1 << " ";
            // if(j != m-1) cout << " ";
            if(minI == -1) break;
            sum += arr[minI][j];

            minI = dp[minI][j].second;
            j++;
        }


        // cout << endl;
        // for(int i = 0; i <n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << dp[i][j].first ;
        //         if(j != m-1) cout << " ";
        //     }
        //     cout << endl;
        // }
        // debug(minI);
        // debug(sum);
        cout << endl;
        cout << sum << endl;
    }
    return 0;
}