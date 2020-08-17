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

bool isPossible(int *arr, int n, int m, int cur_min){

    int studentUsed = 1;
    int pagesReading = 0;

    for(int i = 0; i < n; i++) {

        if(pagesReading + arr[i] > cur_min) 
        {
            studentUsed++;

            pagesReading = arr[i];
            if(studentUsed > m) {
                return false;
            }
        }
        else {
            pagesReading += arr[i];
        }

    }
    return true;
}

int findpages(int *arr, int n, int m) {
    int sum = 0;

    if(n < m) {
        return -1;
    }
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int s = arr[n-1], e = sum;
    int ans = INT_MAX;
    while(s <= e) {

        int mid = (s+e) / 2;
        if (isPossible(arr, n, m, mid)) {
            ans = min(ans, mid);
            e = mid - 1;
        } else {
            s = mid+1;
        }

    }
    return ans;

}

int main() {

    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m; cin >> n >> m;
        int arr[1000];
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout << findpages(arr, n, m) << endl;
    }

    return 0;
}