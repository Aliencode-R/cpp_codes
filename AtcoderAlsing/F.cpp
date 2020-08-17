#include <bits/stdc++.h>
using namespace std;

int matrixChainMul(vector<int> v)
{
    int dp[10][10] = {0};
    int n = v.size() - 1;

    for (int i = 1; i < n; i++)
    {
        int r = 0, c = i;
        while (c < n)
        {
            int val = INT_MAX;
            for (int k = r; k < c; k++)
            {
                val = min(val, dp[r][k] + dp[k + 1][c] + v[r] * v[k + 1] * v[c + 1]);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j< 10; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //         /* code */
    //     }
    //     cout << endl;

    //     /* code */
    // }

    return dp[0][n - 1];
}
void fun(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 0;
    dp[0] = arr[0];
    int ans = max(0, arr[0]);
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    // printf(ans);
    cout << ans;
}

void func(string sarray, int vidx)
{
    if (vidx == sarray.size())
    {

        for (char val : sarray)
            cout << val;
        printf(" ");
        return;
    }

    if (sarray[vidx] == '?')
    {

        sarray[vidx] = '0';
        func(sarray, vidx + 1);

        sarray[vidx] = '1';
        func(sarray, vidx + 1);
        sarray[vidx] = '?';
    }
    else
        func(sarray, vidx + 1);
}

// int fun(int a, int b)
// {
//     if (b <= 0)
//         return 0 ;
//         else return a + fun(a, b - 1);
// }
int func(int[] arr) int low = 0, mid = 0, high = arr.length - 1 while (mid <= high) if (arr[mid] == 0) swap(array, low, mid) low++ mid++ else if (arr[mid] == 1) mid++ else swap(array, high, mid) high--

                                                 return low int main()
{
   
    // int n = 16;
    // int num = 1;
    // int sum = 0;
    // int j = 0;
    // for (int i = 0; i < n;)
    // {
    //     num++;
    //     j++;
    //     if (j == n)
    //     {
    //         j = 0;
    //         i++;
    //     }
    // }
    // cout << num;
}
// cout << fun(2);
// int a = 15, b = 75;
// cout << __gcd(a,b) << " " << __gcd(a,b+a);
// int n = 9;
// for (int i = 1; i <= n; i++)
// {
//     for (int j = 1; j * j <= i; j++)
//     {
//         printf("coding ninja is best \n");
//     }
// }
// int t = 5 ;
// while (t & 1)
// {
//     printf("coding ninja");
//         t = t / 2;
// }
// for (int i = 0; i < 5; i++)
// {
//     int a = 0;
//     for (int j = 0; j < 4; j++)
//     {
//         a++;
//     }
// }
// cout << fun(2,10);
// print(a)
// }