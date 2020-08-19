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
    int n = s.size();
    vector<pair<char,int>> v;
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != s[j]) {
            v.push_back({s[j],i-j});
            j = i;
        }
        if(i == n-1) {
            v.push_back({s[i], i - j + 1});
        }
    }
    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i].first << " " << v[i].second <<endl;
    // }
    bool last2 = false;
    for(int i = 0; i < v.size(); i++) {
        if(last2 == true) {
                last2 = false;
      
            cout << v[i].first;
        }
        else {
            if(v[i].second >= 3 or v[i].second == 2) {
                last2 = true;
                cout << v[i].first << v[i].first;
            }
            else {
                cout << v[i].first;
            }
        }
    }

    return 0;
}
