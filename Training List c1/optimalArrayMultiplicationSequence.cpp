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
int x[12], y[12];
int dp[12][12];
int dir[12][12];

int helper(int from, int to) {
    if(from == to) return 0;
    int &ret = dp[from][to];
    if(ret != -1) return ret;

    ret = exp;
    for(int i = from; i < to; i++) {
        int temp = helper(from, i) + helper(i+1, to) + x[from] * y[to] * y[i];
        if(temp < ret) {
            ret = temp;
            dir[from][to] = i;
        }
    }
    return ret;
}

void print(int from, int to) {
    if(from == to) {
        cout << "A" << from;
        return;
    }
    cout << "(" ;
    print(from, dir[from][to]);
    cout << " x " ;
    print(dir[from][to] + 1, to);
    cout << ")";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    int t = 1;
    while(cin >> n) {
        if (n == 0) break;
        for(int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        memset(dp, -1, sizeof dp);
        helper(1, n);
        cout << "Case " << t++ << ": ";
        print(1, n);
        cout << endl;
    }
    return 0;
}