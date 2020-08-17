#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define ll long long
#define nL "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

void printFactors(int n) {
    vector<pair<int,int>> factors;

    for(int i = 2; i*i <= n; i++) {
        
        if(n % i == 0) {
            int count = 0;
            while( n % i == 0 ) {
                n = n/i;
                count++;
            }
            factors.push_back(make_pair(i,count));
        }
    }
    if(n!=1) { 
        factors.push_back(make_pair(n,1));
    }

    for(auto p: factors) {
        cout << p.first << " " << p.second << endl;
    }
    return;
}

int main() {
    int n; cin >> n;
    printFactors(n);

}