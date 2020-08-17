#include <bits/stdc++.h>
using namespace std;


int main()
{

    int test;
    cin >> test;
    while (test--)
    {

        string str;
        cin >> str;
        priority_queue<int> typ;
        int ans = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '1')
            {
                ans++;
            }
            else
            {
                typ.push(ans);
                ans = 0;
            }
        }




        typ.push(ans);
        int res = 0;
        int i = 0;

        
        while (!typ.empty())
        {
            if (i % 2 == 0)
            {
                res = res + typ.top();
            }
            typ.pop();
            i++;
        }
        cout << res << "\n";


    }
    return 0;
}
