#include <bits/stdc++.h>
using namespace std;

int main()
{

    int test;
    cin >> test;
    while (test--)
    {
        int num;
        cin >> num;



        
        string s(num, '9');
        int x = num / 4;
        int y = num % 4;
        int yup = num;
        for (int i = num - 1; i > num - 1 - x; i--)
        {
            s[i] = '8';
            yup = i;
        }
        --yup;

        if (y != 0)
        {
            s[yup] = '8';
        }
        cout << s << "\n";
    }
    return 0;
}