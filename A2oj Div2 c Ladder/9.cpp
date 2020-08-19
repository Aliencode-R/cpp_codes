#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nL "\n"
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k; cin >> n >> m >> k;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i % 2 == 1) {
                v.push_back(i);
                v.push_back(j);
            } 
            else {
                v.push_back(i);
                v.push_back(m - j + 1);
            }
        }
    }
    int idx = 0;
    for(int i = 1; i < k; i++) {
        // if(i != k) {
            cout << 2 << " " << v[idx] << " " << v[idx + 1] << " " << v[idx + 2] << " " << v[idx + 3] << endl;
            idx += 4;
        // } else {
        //     for()
        // }
    }
    cout << (v.size() - idx) / 2 << " ";
    for(int i = idx; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}
