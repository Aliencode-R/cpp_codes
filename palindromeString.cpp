#include <bits/stdc++.h>
using namespace std;
#define ll long long


 vector<string>  helper(string s)
{
    vector<string> v;   
    if(s.size() == 1)
    {
        string base = s;
        v.push_back(base);
        return v;
    }

    v = helper(s.substr(1));
    vector<string> v2;
    for(int i = 0; i < v.size(); i++)
    {  
        for(int j = 0; j < v[i].size() + 1; j++)
        {
            string temp = v[i];
            temp.insert(temp.begin() + j, 1, s[0]);
            v2.push_back(temp);
        }
    }
    return v2;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<string> v = helper(s);
    for(int i = 0; i < v.size(); i++)
    {
            cout << v[i] << nL;
    }
    return 0;
}