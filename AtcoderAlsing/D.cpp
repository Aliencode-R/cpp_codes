#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
const int nn = 1005;
int boyS[nn][nn] = {0};
int boyE[nn][nn] = {0};
int girlS[nn][nn] = {0};
int girlE[nn][nn] = {0};
int calorie[nn][nn] = {0};

int maxCalories(int m, int n) {
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            boyS[i][j] = calorie[i][j] + max(boyS[i - 1][j], boyS[i][j-1]);
        }
    }

    for(int i = m; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            girlS[i][j] = calorie[i][j] + max(girlS[i + 1][j], girlS[i][j - 1]);
        }
    }

    for(int i = m; i >= 1; i--) {
        for(int j = n; j >= 1; j--) {
            boyE[i][j] = calorie[i][j] + max(boyE[i + 1][j], boyE[i][j + 1]);
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= 1; j--) {
            girlE[i][j] = calorie[i][j] + max(girlE[i - 1][j], girlE[i][j + 1]);
        }
    }

    int ans = 0;
    for(int i = 2; i < m; i++) {
        for(int j = 2; j < n; j++) {
            int ans1 = boyS[i][j - 1] + boyE[i][j + 1] + girlS[i + 1][j] + girlE[i - 1][j];
            int ans2 = girlS[i][j - 1] + girlE[i][j + 1] + boyS[i - 1][j] + boyE[i + 1][j];
            ans = max({ans, ans1, ans2});
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n; cin >> m >> n;
    for(int i = 1; i <= m; i++ ) {
        for(int j = 1; j <= n; j++) {
            cin >> calorie[i][j];
        }
    }
    cout << maxCalories(m, n)  << endl;

    return 0;
}
