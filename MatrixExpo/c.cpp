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
#define REP(i, n) for (int i = 0; i < (n); i++)

struct Matrix
{
    int a[2][2] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix &other)
    {
        Matrix product;
        REP(i, 2)
        REP(j, 2) REP(k, 2)
        {
            product.a[i][k] = (product.a[i][k] + (long long)a[i][j] * other.a[j][k]) % mod;
        }
        return product;
    }
};
Matrix expo_power(Matrix a, long long k)
{
    Matrix product;
    REP(i, 2)
    product.a[i][i] = 1;
    while (k > 0)
    {
        if (k % 2)
        {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> c(2, vector<int>(2));

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}

// vector<vector<int>> pow(vector<vector<int>> arr, int n)
// {
//     // if(n == 1) return arr;
//     vector<vector<int>> a = {{1,0}, {0, 1}};
//     while(n > 0) {
//         if(n % 2 == 1) {
//             a = multiply(a, arr);
//         }
//         arr = multiply(arr,arr);
//         n /= 2;
//     }
//     return a;
// }

vector<vector<int>> pow(vector<vector<int>> A, int p)
{
    if (p == 1)
    {
        return A;
    }
    if (p & 1)
    {
        return multiply(A, pow(A, p - 1));
    }
    vector<vector<int>> X = pow(A, p / 2);
    return multiply(X, X);
}

int fib(int n)
{
    vector<vector<int>> t = {{0,1}, {1,1}};
    vector<int> f1 = {0,1};

    t = pow(t, n-1);
    int res = 0;
    for(int i = 0; i < 2; i++) {
        res += (t[1][i] * f1[i]) % mod;
    }
    return res % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i; cin >> i;
    if (i == 1 or i == 0) {

        cout << i;
        return 0;
    }

    // for(int i = 2; i <= n; i++) {
        int c = fib(i);

        // Matrix single;
        // single.a[0][0] = 0;
        // single.a[0][1] = 1;
        // single.a[1][0] = 1;
        // single.a[1][1] = 1;
        // Matrix total = expo_power(single, i);
        // int b =  total.a[1][0];
        // if(c != b) {
        //     cout << c << " " << b << endl;
        // }
        
        // else
        cout << c << " ";
    // }


    // cout << fib(n);
    return 0;
}