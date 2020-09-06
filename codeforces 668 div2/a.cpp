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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        bool flag = true;
        for(int i = k; i < n; i++) {
            if(s[i] == '?') {
                s[i] = s[i-k];
            } else if(s[i] == '0') {
                if(s[i-k] == '1') {
                    flag = false;
                    break;
                }
                if(s[i-k] == '?') {
                    s[i-k] = '0';
                }
            } else {
                if (s[i - k] == '0')
                {
                    flag = false;
                    break;
                }
                if (s[i - k] == '?')
                {
                    s[i - k] = '1';
                }
            }
        }
        // cout << s << endl;
        if(flag == false) {
            cout << "NO" << endl;
            continue;
        }
        int zero = 0, one = 0, x = 0;
        for(int i = 0; i < k; i++) {
            if(s[i] == '0') {
                zero++;
            } else if(s[i] == '1') {
                one++;
            } else {
                x++;
            }
            if(zero > k/2 or one > k/2) {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << "NO" << endl;
            continue;
        }
        for(int i = k; i < n; i++) {
            if(s[i-k] == '1') {
                one--;
            }
            if (s[i - k] == '0')
            {
                zero--;
            }
            if(s[i] == '0') {
                zero++;
            }
            if(s[i] == '1') {
                one++;
            }
            if (zero > k / 2 or one > k / 2)
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << "NO" << endl;
            continue;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}