#include<bits/stdc++.h>
using namespace std;
int findMinVertex(int* weights, bool* visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == - 1 || weights[i] < weights[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}
void prims(int **edges, int v)
{
    int *parent = new int[v];
    int *weights = new int[v];
    bool* visited = new bool[v];

    for(int i = 0;i < v; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    parent[0] = -1;
    weights[0] = 0;

    for(int i = 0; i < v-1; i++)
    {
        int minVertex = findMinVertex(weights, visited, v);
        visited[minVertex] = true;
		for(int j = 0; j < v; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(edges[minVertex][j] < weights[j]){
					weights[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}

    }
    	for(int i = 1; i < v; i++){
		if(parent[i] < i){
			cout << parent[i] << " " << i << " " << weights[i] << endl;
		}
        else{
			cout << i << " " << parent[i] << " " << weights[i] << endl;
		}
	}

}

int main()
{
    int v , e;
    cin >> v >> e;

    int **edges = new int*[v];
    for(int i = 0;i < v;i++)
    {
        edges[i] = new int[v];
        	for (int j = 0; j < v; j++) {
			edges[i][j] = 0;
		}
    }
    // memset(edges, 0, sizeof(edges));
    for(int i = 0; i< e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    prims(edges, v);
    return 0;
}