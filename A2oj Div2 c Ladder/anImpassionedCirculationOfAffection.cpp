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

const int N = 1502;
const int C = 26;

int ans[C][N] = {{0}};
int q, mi;
char ci;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;

    for(int c = 0; c < C; c++) {
        for(int i = 0; i < n; i++) {
            int replace = 0;
            for(int j = i; j < n; j++) {
                if(s[j] != 'a' + c) replace++;
                ans[c ][replace] = max(ans[c][replace], j - i + 1);
            }
        }

        for(int i = 1; i < N; i++) {
            ans[c ][i] = max(ans[c ][i], ans[c][i-1]);
        }

    }
    int q; cin >> q; 
    while(q--) {
        cin >> mi >> ci;
        cout << ans[ci-'a'][mi] << endl;
    }


    return 0;
}