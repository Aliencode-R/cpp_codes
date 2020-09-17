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
    string s; cin >> s;
    int a = 0; // ending at a 
    int b = 0; // at b
    int c = 0; // at c

    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if(ch == 'a') {
            // take previous a , dont take prev a and start from this a
            a = 2 * a + 1; 
        } else if (ch == 'b') {
            b = 2 * b + a;
            // take previous b, dont take prev b and append b to prev a
        } else if (ch == 'c') {
            c = 2 * c + b;
        }
    }

    cout << c; // ending at c

    return 0;
}