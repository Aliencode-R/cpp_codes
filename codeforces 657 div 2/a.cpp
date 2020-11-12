#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n" 
#define debug(x) cerr << #x << " = " << x << endl;
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define uset unordered_set 
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define inf 1e9
#define infl 1e18
#define int long long

void __print(long x)
{
    cerr << x;
}
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]" << endl; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define deb(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define deb(x...)
#endif

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
        tree_order_statistics_node_update>
        pbds;
string f = "abacaba";
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) {
        int n; cin >> n; 
        string s; cin >> s; 
        int count = 0;
        // int n = s.size();
        int start = -1;
        for(int i = 0; i <= n-7; i++) {
            if(s.substr(i, 7) == "abacaba") {
                count ++;
                if(start == -1)
                start = i;
            }
        }

        int subcount = 0;
        int subcountStart = -1;
        int mx = imin;
        for(int i = 0; i <= n-7; i++) {
            int index = 0;
            bool flag = true;
            bool isq = false;
            int elements = 7;
            for(int j = i; j < 7 + i; j++) {
                if(s[j] == f[index++] or s[j] == '?') {
                    if(s[j] == '?') {
                        isq = true;
                        elements--;
                    }
                    continue;
                }
                flag = false;
                break;
            }
            if(isq and flag) {
                subcount ++;
                if(elements > mx) {
                    mx = elements;
                    subcountStart = i;
                }
            }
        }

        // subcount -= count;
        deb(s , subcount, count, subcountStart, start);

        if(count > 1 or (count == 0 and subcount == 0))  {
            cout << "No" << endl;
            continue;
        }
        if(count == 1) {
            cout << "Yes" << endl;
            for(int i = 0; i < n; i++) {
                if(s[i] == '?') {
                    cout  << 'z' ;
                } else {
                    cout << s[i] ;
                }
            }
            cout << endl;
            continue;
        }
        if(subcount >= 1) {
            string ans;
            // cout << "Yes" << endl;
            for(int i = 0; i < n; i++) {
                if(s[i] != '?') {
                    // cout << s[i];
                    ans += s[i];
                    continue;
                }
                if(i < subcountStart or i >= subcountStart + 7) {
                    // cout << 'z' ;
                    ans += 'z';
                    continue;
                }

                // cout << f[i - subcountStart];
                ans += f[i - subcountStart];

            }

            int count = 0;
            // int n = s.size();
            // int start = -1;
            for (int i = 0; i <= n - 7; i++)
            {
                if (ans.substr(i, 7) == "abacaba")
                {
                    count++;
                }
            }
            if(count == 1) {
                cout << "Yes" << endl;
                cout << ans;
            } else {
                cout << "No";
            }
            cout << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}