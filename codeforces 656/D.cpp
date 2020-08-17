#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //write your code
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int cur_sum = 1, sum = 0;
        string A;
        getline(cin, A);
        int len = A.length();
        int index = 0;
        int cur = 0;
        sort(A.begin(), A.end());
        for (int i = 1; i < len; i++)
        {
            if (A[i] != A[i - 1])
            {
                cur_sum = 1;
                index = i;
            }
            else
            {
                cur_sum++;
                if (sum == cur_sum)
                {
                    if (A[i] < A[cur])
                    {
                        cur = index;
                    }
                    else if (sum < cur_sum)
                    {
                        sum = cur_sum;
                        cur = index;
                    }
                }
            }
        }
        // for (int i = cur; i < cur + sum; i++)
        // {
        //     // cout << A[i];
        // }
        // cout << "\n";
    }

    return 0;
}