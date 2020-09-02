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
#define exp 1000000000

#define sz(x) (int((x).size()))
#define int long long

int k; 
vector<int> b, a, c;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> C(k+1, vector<int>(k+1));
     for (int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= k; j++) {
            for(int x = 1; x <= k; x++) {
                C[i][j] += (a[i][x] * b[x][j]) % exp; 
            }
        }
    }
    return C;
}

    vector<vector<int>> pow(vector<vector<int>> A, int p)
{
    if(p == 1) {
        return A;
    }
    if(p&1) {
        return multiply(A, pow(A, p-1));
    }
    vector<vector<int>> X = pow(A, p/2);
    return multiply(X, X);
}

    int compute(int n)
{
    if(n == 0) return 0;
    if(n <= k) {
        return b[n-1];
    }
    vector<int> f1(k+1);
    for(int i = 1; i <= k; i++) {
        f1[i] = b[i-1];
    }

    vector<vector<int>> T(k+1, vector<int>(k+1));
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            if(i < k) {
                if(j == i+1) {
                    T[i][j] = 1;
                }
                else {
                    T[i][j] = 0;
                }
            } 
            else {
                T[i][j] = c[k-j];
            }
        }
    }

    T = pow(T, n-1);
    int res  = 0;
    for(int i = 1; i <= k; i++) {
        res = (res+ (T[1][i]*f1[i]))%exp;
    }
    return res%exp;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, num; cin >> t;
    while(t--) {

        cin >> k;

        for(int i = 0; i < k; i++) {
            cin >> num;
            b.push_back(num);
        }
        for(int i = 0; i< k; i++) {
            cin >> num;
            c.push_back(num);
        }
        cin >> n;
        cout << compute(n) << endl;
        b.clear();
        c.clear();
    }


    return 0;
}