#include<bits/stdc++.h>
using namespace std;

void dfs(int arr[][100], int n, int sv, bool visited[])
{
    cout << sv << " ";
    visited[sv] = true;
    for(int i = 0; i < n; i++)
    {
        if(arr[sv][i] == 1)
        {
            if(visited[i])
            {
                continue;
            }
            dfs(arr, n, i, visited);
        }
    }
}
void bfs(int arr[][100], int n,int sv, bool visited[])
{
    // int vertex = 0;
    queue<int> remaining;
    remaining.push(sv);

        visited[sv] = true;

    while(remaining.size() != 0)
    {
        int cur = remaining.front();
        remaining.pop();
        cout << cur << " ";
        // visited[cur] = true;
        for(int i = 0; i < n; i++)
        {
            if(arr[cur][i] == 1)
            {
                if(!visited[i])
                {
                    remaining.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}
void printBfs(int arr[][100], int n)
{
        bool visited[n];
    memset(visited, false, sizeof(visited));
       cout << "Bfs : " ;
    for(int i = 0; i < n;i++)
    {
        if(!visited[i])
            dfs(arr, n,i , visited);
    }
    cout << endl;


}

void printDfs(int arr[][100], int n)
{
    bool visited[n];
    memset(visited, false, sizeof(visited));
       cout << "dfs : "  ;
    for(int i = 0; i < n;i++)
    {
        if(!visited[i])
            dfs(arr, n,i, visited);
    }
cout << endl;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int arr[v][100];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        arr[f][s] = 1;
        arr[s][f] = 1;
    }

 
    // cout << "\nbfs : ";
    printDfs(arr, v);
    printBfs(arr, v);
    return 0;
}