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

int shortestSubarray(vector<int> A, int K)
{
    int N = A.size(), res = N + 1;
    deque<int> d;
    for (int i = 0; i < N; i++)
    {
        cout << "I " << i << endl;
        if (i > 0)
            A[i] += A[i - 1];
        if (A[i] >= K)
            res = min(res, i + 1);
        while (d.size() > 0 && A[i] - A[d.front()] >= K) {
            res = min(res, i - d.front()); 
            cout << "popfront " << d.front() << endl;
            d.pop_front();
        }
        while (d.size() > 0 && A[i] <= A[d.back()]) {
            cout << "popback " << d.back() << endl;
            d.pop_back();
        }
        d.push_back(i);
        for(auto x : d) cout << x << "-" ;
        cout << endl;
    }
    return res <= N ? res : -1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {1, 2, 5, -8, -7, 11, 19, -10, 21};
    cout << endl << shortestSubarray(v, 8);
    return 0;
}
