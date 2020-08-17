#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

class graph{
    ll V;
    list<pair<int,int>> *l;


public: 
    graph(int mv) {
        V = mv;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int z) {
        l[u].push_back(make_pair(v,z));
        l[v].push_back(make_pair(u,z));
    }

    int dfsHelper(int node, bool *visited, int *count, int &ans) {
        visited[node] = true;
        count[node] = 1;

        for(auto p: l[node]) {
            int nbr = p.first;
            int wt = p.second;
            if(visited[nbr] == false) {
                count[node] += dfsHelper(nbr, visited, count, ans);
                int nx = count[nbr];
                int ny = V - nx;

                ans += 2 * min(nx, ny) * wt;
            }
        }
        return count[node];
    }

    int dfs() {
        bool visited[V] = {0};
        int count[V] = {0};

        int ans = 0;
        dfsHelper(1, visited, count, ans);
        return ans;
    }

};

int32_t main()
{

    return 0;
}




