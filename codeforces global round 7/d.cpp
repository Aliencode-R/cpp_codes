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

bool check(string t, int s, int e) {
    while(s <= e) {
        if(t[s] != t[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
            // cout << 1111;
    int t; cin >> t;
    // cout << "here";
    // cout << t;
    while(t--) {
        string s; cin >> s;
        int n = s.size();
        // a->>>>
        int op1 = 1;
        for(int i = 1; i < n; i++) {
            if(check(s, 0, i)) 
            op1 = max(op1, i+1);
        }
        // <<<== b
        int op2 = 1;
        for(int i = n-2; i >= 0; i--) {
            if(check(s, i, n-1))
            op2 = max(op2, n - i);
        }
        
        // a -->> ifjaofdj << ---b
        int op3 = 0;

        int ai = 0, bi = n-1;
        while(ai <= bi and s[ai] == s[bi] ) {
            ai++;
            bi--;
            if(ai == bi) op3++;
            else
                op3 += 2;
        }
        int alen = ai;
        int blen = bi;
        cout << alen << ",," << blen << endl;
        int op31 = 1;
        int op32 = 1;
        if(ai > 0 and bi < n-1 and ai < bi) {
            for(int i = ai ; i <= bi; i++) {
                if(check(s, ai, i ))
                op31 = max(op31, i - ai);
            }
            for(int i = bi; bi >= ai; i--) {
                if(check(s, i, bi))
                op32 = max(op32, bi - i + 1);
            }
        }
        int extra = 0;
        if(op31 > 1) {
            extra = op31;
        }
        if(op32 > 1) {
            extra = op32;
        }
        cout << ai << "--" << bi << endl;

        int len = max({op1, op2, op3 + extra});
        if(len == op1) {
            cout << s.substr(0, op1);
            cout << "case1 ";
        } else if(len == op2) {
            int start = n - op2;

            cout << s.substr(start);
            cout << "case2" ;
        } else {
            cout << "case3 " ;
            if(extra == 0) {
                cout << s.substr(0, alen);
                int start = n - blen;
                cout << start << "1";
                // cout << s.substr(start);
            }
            else if(extra == op31) {
                cout << s.substr(0, op31);
                int start = n - blen;
                cout << start << "2";

                // cout << s.substr(start);
                // cout << s.substr(blen);
            } else if(extra == op32) {
                cout << s.substr(0, alen);
                int start = n - op32;
                cout << start << "3";

                // cout << s.substr(start);
            }
        }
        cout << endl;
    }
    return 0;
}