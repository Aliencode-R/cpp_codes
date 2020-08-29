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
    int hy, ay, dy;
    cin >> hy >> ay >> dy;
    int hm, am, dm; 
    cin >> hm >> am >> dm;
    int h, a, d; cin >> h >> a >> d;

    int ans = INT_MAX;
    for(int i = ay; i <= 200; i++) {
        for(int j = dy; j <= 100; j++) {
            if(i == dm or j == am) continue;
            int nh = (hm * (i - dm)) / (am - j);
            int cost = (nh-hy) * h + (i - ay) * a + (j - dy) * d;
            ans = min(ans, cost); 
        }
    }
    cout << max(0ll, ans);

    return 0;
}