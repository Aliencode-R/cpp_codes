// https: //codeforces.com/contest/515/problem/C
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
    int n; cin >>n;
    string s; cin >> s;
    // int n = s.size();
    int arr[s.size()]; 
    for(int i = 0; i < n; i++) {
        arr[i] = s[i] - '0';
    }
    // bool flag = true;
    // for(int i = 0; i < s.size(); i++) {
    //     int element = s[i] - '0';
        // if(element > 2 and element % 2 == 0) {
        //     flag = false;
        // }
    // }
    // if(flag) {
    //     sort(arr + n, arr);
    //     for(int i = 0; i < n; i++) cout << arr[i];
    //     return 0;
    // }
    vector<int> v; 
    for(int i = 0; i < n; i++) {
        if(arr[i] == 4) {
            v.push_back(2);
            v.push_back(2);
            arr[i] = arr[i] - 1;
            v.push_back(arr[i]);
        }
        else if(arr[i] == 8) {
            v.push_back(2);
            v.push_back(2);
            v.push_back(2);
            arr[i] = arr[i] - 1;
            v.push_back(arr[i]);
        } else if(arr[i] == 6){
            v.push_back(3);
            v.push_back(5);
        }
        else if(arr[i] == 9) {
            v.push_back(3);
            v.push_back(7);
            v.push_back(3);
            v.push_back(2);
        }
         else if(arr[i] != 1 and arr[i] != 0){
            v.push_back(arr[i]);
        }
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }

    return 0;
}