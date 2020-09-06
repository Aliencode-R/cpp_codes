#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 22;
vector<int> graph[N];

void bfs(int src, int n, int &ans)
{
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (q.size() != 0)
    {
        int cur = q.front();
        q.pop();

        for (auto nbr : graph[cur])
        {
            if (dist[nbr] == INT_MAX)
            {
                // neighbour not vistited
                dist[nbr] = dist[cur] + 1;
                q.push(nbr);
            }
            else if (dist[nbr] >= dist[cur])
            {
                // backedge discoverd , not parent ;)
                // potential ans , + 1 for backedge
                ans = min(ans, dist[nbr] + dist[cur] + 1);
            }
        }
    }
}

int main()
{
    // 5 6 1 2 1 3 2 4 2 5 4 5 5 3
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = n + 1;
    // we have to start bfs from every node , to get the correct ans 
    // we only get the correct ans - if the src node is in the 
    // cycle 
    for (int i = 1; i <= n; i++)
    {
        bfs(i, n, ans);
    }
    if (ans == n + 1)
    {
        cout << "no cycle" << endl;
    }
    else
    {
        cout << "shortest cycle is of length: " << ans << endl;
    }
    return 0;
}