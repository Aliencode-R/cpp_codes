#include<bits/stdc++.h>
using namespace std;

void dfs(int **edges, int n, int sv, bool* visited, vector<int>& v)
{
    visited[sv] = true;
    v.push_back(sv);
    for(int i = 1; i <= n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i])
        {
            dfs(edges,n,i,visited,v);
        }
    }
}

vector<vector<int>> allConnectedComponents(int **edges, int n)
{
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            vector<int> v;
            dfs(edges,n,i,visited,v);
            ans.push_back(v);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int p[n+1], q[n+1];
        for(int i = 1; i <= n; i++)
        {
                cin >> p[i];   
        }
        for(int i = 1; i <= n; i++)
        {
                cin >> q[i];
        }
        int **edges = new int*[n+1];
        for(int i = 1; i <= n; i++)
        {
            edges[i] = new int[n+1];
            for(int j = 1; j <= n; j++)
            {
                edges[i][j] = 0;
            }
        }        
        for(int i = 0; i < m; i++)
        {
            int f, s;
            cin >> f>> s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        int flag = 1;
        vector<vector<int>> components = allConnectedComponents(edges, n);
       
        for(int i = 0; i < components.size(); i++)
        {
            vector<int> component = components[i];
            vector<int> s1;
            vector<int> s2;
           
            for(int j = 0; j < component.size(); j++)
            {
                s1.push_back(p[component[j]]);
                s2.push_back(q[component[j]]);
            }
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());

            for(int j = 0; j < s1.size(); j ++)
            {
                if(s1[j] != s2[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
               
                break;
            }
          
        }
        if(flag == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
	return 0;
}
