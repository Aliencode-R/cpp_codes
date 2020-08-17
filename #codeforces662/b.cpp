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
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    umap<int,int> m;
    umap<int,int> rev;

    for(int i = 0; i < n; i++ ) {
        int a; cin >> a;
        m[a]++;
    }
    for(auto p : m) {
        if(p.second >= 8) {
            rev[8]++;
        }
        else if(p.second >= 6) {
            rev[6] ++;
        }
        else if (p.second >= 4) {
            rev[4] ++;
        }   
        else if (p.second >= 2) {
            rev[2] ++;
        }

    }

    int q; cin >> q;
    while(q--) {
        char c; cin >> c;
        int a; cin >> a;
        if(c == '+') {
            m[a]++;
            if(m[a] == 2) {
                rev[2]++;
            }
            if (m[a] == 4) {
                rev[2]--;
                rev[4]++;
            }
            if (m[a] == 6) {
                rev[4]--;
                rev[6]++;
            }
            if(m[a] == 8) {
                rev[8]++;
                rev[6]--;
            }
        }
        else {
            m[a]--;
            if (m[a] == 1) {
                rev[2]--;
            }
            if (m[a] == 3) {
                rev[4]--;
                rev[2]++;
            }
            if (m[a] == 5) {
                rev[6]--;
                rev[4]++;
            }
            if(m[a] == 7) {
                rev[8]--;
                rev[6]++;
            }
        }
        if(rev[4] >= 1 or rev[6] >= 1 or rev[8] >= 1) {
            // cout << "here" << endl;
            if (rev[4] >= 2 or rev[6] >= 2 or(rev[4] >= 1 and rev[6] >= 1) or (rev[6] >= 1 and rev[2] >= 1) or rev[2] >= 2 or rev[8] >= 1) {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}

