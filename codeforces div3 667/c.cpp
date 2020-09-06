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

bool isGood(int a, int b, int d, int n, int temp) {
    if(d % temp != 0) {
        return false;
    }
    while(b > 0 and n > 0) {
        b -= temp;
        n--;
    }
    if(b > a) return false;
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n, x, y; cin >> n >> x >> y;
        // vector<int> factors = printFactors(y-x);
        int d = y-x;
        if(n == 2) {
            cout << x << " " << y << endl;
            continue;
        }
        if(d == 0) {
            for(int i = 0; i < n; i++) {
                cout << x << " ";
            }
            cout << endl;
            continue;
        }
        vector<int> ans;
        bool flag = false;
        for(int i = n-1; i > 0; i--) {

            if(d % i != 0 ) continue;
            int temp = 0;
            int dif = d/i;
            for(int j = 0; j < i; j++) {
                temp += dif;
            }
            if(temp < d) continue;
            int val = y;
            while(n > 0 and val > 0) {
                ans.push_back(val);
                val -= dif;
                n--;
            }
            val = y + dif;
            while(n > 0) {
                ans.push_back(val);
                val += dif;
                n--;
            }

            for (auto u : ans)
                cout << u << " ";
            cout << endl;
            flag = true;
            break;
            // continue;
        }
        if(flag) continue;
        int dif = d;
        int val = y;
        while (n > 0 and val > 0)
        {
            ans.push_back(val);
            val -= dif;
            n--;
        }
        val = y + dif;
        while (n--)
        {
            ans.push_back(val);
        }

        for (auto u : ans)
            cout << u << " ";
        cout << endl;

        for(auto u: ans) cout << u << " ";
        cout << endl;
    }
    return 0;
}