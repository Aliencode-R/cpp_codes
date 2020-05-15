#include <bits/stdc++.h>
using namespace std;
#define ll long long

void constructZ(string str, int *z)
{
    int len = str.size();
    int l, r, k;
    l = 0;
    r = 0;
    for(int i = 1; i < len; i++)
    {
        if(i > r)
        {
            l = r = i;
            while(r < len && str[r-l] == str[r])
            {
                r++;
            }
            z[i] = r-l;
            r--;
        }
        else
        {
            k = i-l;

            if(z[k] <= r-i)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while(r < len && str[r-l] == str[r])
                {
                    r++;
                }
                z[i] = r-l;
                r--;
            }
            
            
        }
        
    }
}

void zSearch(string text, string pattern)
{
    string concat = pattern + "$" + text;
    int len = concat.size();
    int z[len];
    constructZ(concat, z);

    for(int i = 1; i < len; i++)
    {
        if(z[i] == pattern.size())
        {
            cout << i - pattern.size() - 1 << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    getline(cin,text);
    getline(cin, pattern);

    zSearch(text, pattern);

    return 0;
}
