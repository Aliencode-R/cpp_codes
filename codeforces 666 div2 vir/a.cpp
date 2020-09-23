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
        vector<string> v;
        int tot = 0;
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            v.push_back(s);
            tot += s.size();
        }
        if(tot % n != 0) {
            cout << "NO" << endl;
            continue;
        }
        int arr[26] = {};
        // umap<char,int> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < v[i].size(); j++) {
                int index = v[i][j] - 'a';
                arr[index]++;
            }
        }

        bool flag = true;
        for(int i = 0; i < 26; i++) {
            if(arr[i] % n != 0) {
                flag = false;
                break;
            }
        }

        if(flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}