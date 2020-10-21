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
    int n, p; cin >> n >> p;
    p--;
    string s; cin >> s;
    int ans = 0;
    int i = 0, j = n-1;
    int leftI = imax;
    int rightI = -1;
    int leftJ = imax;
    int rightJ = -1;

    while(i <= j) {
        int c1 = s[i] - 'a' + 1;
        int c2 = s[j] - 'a' + 1;
        
        ans += min((26 + c1 - c2) % 26, (26 + c2 - c1) % 26);
        if(s[i] != s[j]) {
            leftI = min(leftI, i);
            rightI= max(rightI, i);
            leftJ = min(leftJ, j);
            rightJ = max(rightJ, j);
            // rightmost = j;
        }
        // if(s[i] != s[j]) {
        // }
        i++;
        j--;
    }
    // cout << ans << endl;
    // cout << leftI << " " << rightI << endl;
    // cout << leftJ << " " << rightJ << endl;

    if(ans == 0) {
        cout << 0;
        return 0;
    }
    if(p <= leftI) {
        ans += rightI - p;
    }
    else if(p >= rightJ) {
        ans += p - leftJ;
    }
    else if(p >= leftI and p <= rightI) {
        ans += min(p - leftI, rightI - p);
        ans += rightI - leftI;
    }
    else if(p <= rightJ and p >= leftJ) {
        ans += min(rightJ - p, p - leftJ);
        ans += rightJ - leftJ;
    }
    else if(p < leftJ and p > rightI) {
        ans += min(p - leftI, rightJ - p);
    }
    cout << ans;


    return 0;
}














