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
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n; 
        string s; cin >> s;
        string a, b;
        bool equal = true;
        int big = -1;
        int toggle = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '2') {
                if(equal) {
                    a += '1';
                    b += '1';
                }
                else {
                    a += '0';
                    b += '2';
                }               
            }
            if(s[i] == '0') {
                a += '0';
                b += '0';
            }
            if(s[i] == '1') {
                if(equal) {
                    a += '1';
                    b += '0';
                    equal = false;
                } else {
                    a += '0';
                    b += '1';
                }
            }
        }
        cout << a << endl << b << endl;
    }
    return 0;
}