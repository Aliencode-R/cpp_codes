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
    string s; cin >> s;
    s[n-1]++;
    int i = n - 1;
    while(i >= 0 and i < n) {
        if(s[i] - 97 >= p) {
            s[i] = 'a';
            i--;
            if(i >= 0) s[i]++;
        }
        else if ((i >= 1 && s[i] == s[i - 1]) || (i >= 2 && s[i] == s[i - 2]))
        {
            s[i]++;
        }
        else
        {
            i++;
        }
    }
    if (i == -1)
        cout << "NO" << endl;
    else
        cout << s << endl;
    return 0;
}