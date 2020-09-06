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

        int a, s; cin >> a >> s;
        // int temp = a;
        // int digits = 0;
        // while(temp > 10) {
        //     temp /= 10;
        //     digits++;
        // }

        // if(temp > s) {
        //     cout << 1; 
        //     for(int i = 0;i < digits; i++) {
        //         cout << 0 ;
        //     }
        //     continue;
        // }
        string str = to_string(a);
        // cout << str << endl;
        int n = str.size()-1;
        int sum = 0;
        for(int i = 0; i <= n; i++) {
            sum += str[i] - '0';
        }
        int carry = 0;
        for(int i = n; i >= 0; i--) {
            int num = str[i] - '0';
            if(carry == 1) {
                num++;
            }
            sum -= num;
            str[i] = '0';
            if(sum <= s) {
                carry = 0;
                break;
            }
            carry = 1;
        }
        if(carry == 1) {
            char c = '1';
            str = c + str;
        }
        cout << stoll(str) - a;
        cout << endl;
    }
    return 0;
}