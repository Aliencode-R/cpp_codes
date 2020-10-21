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

string letters = "012346789ABCDEF";
int toInt(char c) { return letters.find(c); };

int FromAnyBaseDecimal(string in, int base) {
    int res = 0;
    for(int i = 0; i < in.size(); i++) {
        res *= base, res += toInt(in[i]);
    }
    return res;
}

string fromDecimalToAnyBase(int number, int base) {
    if(number == 0) {
        return "0";
    }
    string res = "";
    for(; number; number /= base) 
        res = letters[number % base] + res;
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fromDecimalToAnyBase(5, 3);
    return 0;
}