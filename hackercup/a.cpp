#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("D:/cpp_codes/hackercup/input.txt", "r", stdin);
        freopen("D:/cpp_codes/hackercup/output.txt", "w", stdout);
        #endif

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;

        string str;
        cin >> str;
        cout << "Case #" << t << ": ";

        stack<int> s;

        for (auto x : str)
        {
            if (s.size() == 0)
            {
                s.push(x);
                continue;
            }
            if (s.top() != x)
            {
                s.pop();
            }
            else
            {
                s.push(x);
            }
        }
        cout << (s.size() == 1 ? "Y" : "N") << endl;
    }
    return 0;
}
