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

    string s; cin >> s;
    if(s[0] == '0') {
        cout << "NO" ;
        return 0;
    }
    int a, b; cin >> a >> b;
    int n = s.size();
    int rema[n] = {}, remb[n] = {};

    // calc for a 
    rema[0] = (s[0] - '0') % a;
    for(int i = 1; i < n; i++) {
        rema[i] = (rema[i-1] * 10 + (s[i] - '0')) % a;
    }
    // now for b
    remb[n-1] =( s[n-1] - '0') % b;
    int p = 1;
    for (int i = n-2; i >= 0; i--) {
        p = (p*10) % b;
        remb[i] = (((s[i]-'0') * p) + remb[i+1]) % b;
    }
//     for(int i = 0; i < n; i++) {
//         cout << rema[i];
// }
//     cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << remb[i];
//     }

    for(int i = 0; i < n-1; i++) {
        if(rema[i] == 0 and remb[i+1] == 0 and s[i+1] != '0'){
            
            cout << "YES" << endl;
            cout << s.substr(0, i+1) << endl << s.substr(i+1, n);
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
