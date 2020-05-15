#include <bits/stdc++.h>
using namespace std;
#define ll long long

int *getLps(string pattern)
{
    int len = pattern.size();
    int lps[len];
    memset(lps, 0, sizeof(lps));

    lps[0] = 0;
    int i = 1;
    int j = 0;

    while(i < len)
    {
        if(pattern[i] == pattern[j])
        {
            lps[i] = j+1;
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }   
        }
    }
    return lps;
}
int kmp(string text, string pattern)
{
    int lenT = text.size();
    int lenP = pattern.size();

    int i = 0, j = 0;

    int* lps = getLps(pattern);
    while(i < lenT && j < lenP)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
            
        }
        
    }
    if(j == lenP)
    {
        return i - lenP;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    // cin >> text >> pattern;
    getline(cin, text);
    getline(cin, pattern);
    cout << kmp(text,pattern);

    return 0;
}