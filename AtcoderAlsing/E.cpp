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
int searchMatrix(vector<vector<int>> &A, int B)
{
    int n = A.size();
    int col = A[0].size();

    int start = 0;
    int end = n - 1;
    // if (B > A[0][0])
    //     return 0;

    int r = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (A[mid][0] < B)
        {
            r = max(r, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        cout << r << endl;
    }
    cout <<end << "  ";
    // cout << "  p ";
    return binary_search(A[r].begin(), A[r].end(), B) ? 1 : 0;
}

int bu(int n) {
    int dp[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = imax;
    }
    dp[1] = 0;
    for(int i = 1; i<= n; i++) {
        if(i+1<= n)
            dp[i+1] = min(dp[i+1], 1+dp[i]);
        if (2 * i <= n)
            dp[2 * i] = min(dp[2 * i], 1 + dp[i]);
        if (3 * i <= n)
            dp[3 * i] = min(dp[3 * i], 1 + dp[i]);
    }
    return dp[n];
}

int mincoins(int *arr, int t, int n) {
    int dp[n+1] = {0};
    for(int i = 1; i<= n; i++) {
        int ans = imax;
        for(int j = 0; j < t; j++) {
            if(i - arr[j] >= 0) {
                ans = min(ans, dp[i - arr[j]]);
            } else {
                break;
            }
        }
        dp[i] = ans + 1;
    }
    return dp[n];
}

int recursiveLcs(string a, string b, int dp[][100]) {
    int n = a.size();
    int m = b.size();

    if(m == 0 or n == 0) {
        return 0;
    }
    if(dp[n][m] != -1) return dp[n][m];
    int ans = 0;
    if(a[0] == b[0]) {
        ans =  1 + recursiveLcs(a.substr(1), b.substr(1), dp);
    } else {
        int op1 = recursiveLcs(a, b.substr(1), dp);
        int op2 = recursiveLcs(a.substr(1), b, dp);
        ans =  max(op1, op2);
    }
    return dp[n][m] = ans;
}

int alpha(int n, int *arr) {
    int dp[n+1] = {0};

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] += dp[i-1];
        if(arr[i-2]*10 + arr[i-1] <= 26) {
            dp[i] += dp[i-2];
        } 
    }
    for(int i = 0; i<= n; i++) cout << dp[i] << " " ;
    cout << endl;
    return dp[n];
}

int lis(int *arr, int n) {
    int dp[n] = {0};
    dp[0] = 1;
    for(int i = 1; i<n; i++) {
        int ans = 1;
        for(int j = 0; j < i;j++) {
            if(arr[i] > arr[j]) {
                ans = max(ans, 1+dp[j]);
            }
        }
        dp[i] = ans;
    }
    int ans = imin;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

void vanya(){
    int n; cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int dp[n][101] = {0};

    // dp[0][arr[]]
    for(int i = 0; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            for(int k = 0; k < 101; k++) {
                
            }
        }
    }

}
void solve(int* one, int* two, int k){

    unordered_map<int,int> idxMap;
    for (int i = 0; i < k; i++)
        min = 10000;
         int oneIdx = -1;
          int twoIdx = -1;

                                               for (int j = 0; j < one.length; j++){
                                                if (idxMap[j] == two.length) continue;

                                               if (one[j] + two[idxMap[j]] < min)
                                                   min = one[j] + two[idxMap[j]];
                                                    oneIdx = j;
                                                             twoIdx = idxMap[j];
                                                   
                                               }
            idxMap[oneIdx]++ printf(one[oneIdx] + " " + two[twoIdx]);
                // Print(“, ”)
                cout << " ,";
}

    int main()
{
    int one[] = {1,7,11};
    int two[]  = {2, 4, 6};
    int k = 3;
    solve(one, two, k);
    // vanya();
    // int n; cin >> n;
    // int arr[n]; 
    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // cout << lis(arr,n) ;
    // cout << alpha(n, arr);
    // string a, b; 
    // cin >> a >> b;
    // int dp[100][100];
    // // for(int i = 0; i <= a.size(); i++) {
    // //     for()
    // // }
    // memset(dp,-1,sizeof(dp));
    // cout << recursiveLcs(a, b, dp);
//   int n; cin >> n;
//   int arr[] = {1,7,10};
//     cout << mincoins(arr, 3, n);
//   cout << bu(n) ;

    return 0;
}