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
    int n; cin >> n;
    int k1; cin >> k1;
    queue<int> q1;
    for(int i = 0; i < k1; i++) {
        int num; cin >> num;
        q1.push(num);
    }
    int k2;
    cin >> k2;
    queue<int> q2;
    for (int i = 0; i < k2; i++)
    {
        int num;
        cin >> num;
        q2.push(num);
    }

    int f1 = q1.front();
    int f2 = q2.front();

    int time = 1;

    if(f1 < f2) {
        q1.pop();
        q2.pop();
        q2.push(f1);
        q2.push(f2);
    } else {
        q1.pop();
        q2.pop();
        q1.push(f2);
        q1.push(f1);
    }

    while(q1.size() != 0 and q2.size() != 0) {
        int nf1 = q1.front();
        int nf2 = q2.front();
        // or (nf1 == f1 and nf2 == f2 and q1.size() == k1 and q2.size() == k2)
        if(time > 20000 ) {
            cout << -1;
            return 0;
        }
        time++;
        if (nf1 < nf2)
        {
            q1.pop();
            q2.pop();
            q2.push(nf1);
            q2.push(nf2);
        }
        else
        {
            q1.pop();
            q2.pop();
            q1.push(nf2);
            q1.push(nf1);
        }
    }
    cout << time << " ";
    if(q1.size() == 0)
        cout << 2;
    if (q2.size() == 0)
        cout << 1;

    return 0;
}