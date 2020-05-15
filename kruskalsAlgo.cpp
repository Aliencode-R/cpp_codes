#include<bits/stdc++.h>
using namespace std;

class edge
{
    public:
        int source, dest, wt;
};
bool compare(edge e1, edge e2)
{
    return e1.wt < e2.wt;
}
int findParent(int v, int *parent)
{
    if(parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}
void kruskals(edge *input, int v, int e)
{
    sort(input, input+e, compare);

    edge *output = new edge[v-1];
    int *parent = new int[v];
    for(int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    int count = 0; 
    int i = 0;
    while(count != v-1)
    {
        edge cur = input[i];
        int srcParent = findParent(cur.source, parent);
        int destParent = findParent(cur.dest, parent);

        if(srcParent != destParent)
        {
            output[count] = cur;
            count++;
            parent[srcParent] = destParent;
        }
        i++;
    }
    
    for(int i = 0; i < v-1; i++)
    {
        if(output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].wt << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " " << output[i].wt << endl;
        }
        
    }



}

int main()
{
    int v, e;
    cin >> v >> e;
    edge *input = new edge[e];
    for(int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edge *e = new edge;
        e -> source = s;
        e -> dest = d;
        e ->wt = w;
        input[i] =*e;
    }
    kruskals(input, v, e);
    cout << endl;
    return 0;
}