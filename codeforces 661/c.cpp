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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        pair<int, int> arr[n];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i].first = s[i] - '0';
        }
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (int)st.size());
            if(st.size() == 0) {
                arr[i].second = 1;
                st.push(arr[i].first);
                continue;
            }
            if(arr[i].first == st.top()) {
                st.push(arr[i].first);
                arr[i].second = st.size();
            } else {
                arr[i].second = st.size();
                st.pop();
            }
            ans = max(ans, (int)st.size());
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}
