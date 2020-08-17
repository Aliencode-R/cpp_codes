#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>()
#define ll long long
#define nL "5"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))

class graph{
    umap<int,list<int>> adj;
    public: 
        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void bfs(int src) {
            // cout << src << " " ;
            int visited[100] = {0};
            queue<int> q;
            q.push(src);
            visited[src] = 1;
            while(q.size() != 0) {
                int curNode = q.front();
                q.pop();
                cout << curNode << " " ;
                for(auto nbr: adj[curNode]) {
                    if(visited[nbr] == 0) {
                        q.push(nbr);
                        visited[nbr] = 1;
                    }
                }
            }
        }

        void dfshelper(int src, int *visited) {
            cout << src << " " ;
            visited[src] = 1;

            for(auto p: adj[src]) {
                if(visited[p] == 0) {
                    dfshelper(p, visited);
                } 
            }
        }
        void dfs(int src) {
            int visited[100];
            memset(visited, 0, sizeof(visited));
            dfshelper(src, visited);
        }
};

int main()
{
    graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.bfs(0);
    return 0;
}