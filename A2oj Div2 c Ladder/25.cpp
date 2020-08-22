#include <bits/stdc++.h>
using namespace std;
#define endl "\n" 
#define ll long long
// #define pb push_back
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

bool isPossible(int maxTillNow,int r,int cb, int cs, int cc, int nb, int ns, int nc, int pb, int ps, int pc)
{
    int b = max(0ll, cb * maxTillNow - nb) * pb;
    int s = max(0ll, cs*maxTillNow - ns) * ps;
    int c = max(0ll, cc * maxTillNow - nc) * pc;
    int fx = s + b + c;
    if(fx <= r) return true;
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int cb = 0, cs = 0, cc = 0;
    for(auto c : s) {
        if(c == 'B')
            cb++;
        if (c == 'S')
            cs++;
        if (c == 'C')
            cc++;
    }
    // cout << cb << " " <<  cs << " " << cc << endl;
    int nb, ns, nc; cin >> nb >> ns >> nc;
    int pb, ps, pc; cin >> pb >> ps >> pc;
    int r; cin >> r;
    int start = 0, end = r*100;
    int ans ;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(isPossible(mid, r, cb, cs, cc, nb, ns, nc, pb, ps, pc)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << ans;
    return 0;
}