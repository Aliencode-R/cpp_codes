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
    string s, t; cin >> s >> t;
    umap<char, int> m;
    for(char c : t) m[c]++;
    int yay = 0, nay = 0;
    for(char &c : s) {
        if(m[c] > 0) {
            
            m[c]--;
            yay++; 
            c = '.';
        }
    }
    for(char c : s) {
        if(c == '.')continue;
        
        if(islower(c) and m[toupper(c)]) {
            m[toupper(c)] --;

            nay++;

        } else if (isupper(c) and m[tolower(c)] ){
            m[tolower(c)] --;
            nay++;
        }

    }
    // cout << s;
    cout << yay << " " << nay;
    return 0;
}