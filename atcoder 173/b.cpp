#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
// #define a first
// #define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ac = 0, tle = 0, wa = 0,re = 0;
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s == "AC") {
            ac++;
        }if (s == "TLE")
        {
            /* code */
            tle++;
        }
        if(s == "RE") {
            re++;
        }
        if(s == "WA") {
            wa ++;
        }
        
    }
    cout << "AC x " << ac << endl;
    cout << "WA x " <<wa << endl;
    cout << "TLE x " <<tle << endl;
    cout << "RE x " << re << endl;
    return 0;
}
