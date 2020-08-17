#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

vector<int> graph[N];
int tin[N], tout[N], timer;

// check whether x is an ancestor of y or not
bool isAncestor(int x, int y) {
    return tin[x] <= tin[y] and tout [y] <= tout[x];
}

void eulerTour_3(int cur, int par)
{
    // first enter only
    // cout << cur << " ";
    tin[cur] = ++timer; // enter a node
    for (auto nbr : graph[cur])
    {
        if (nbr != par)
        {
            eulerTour_3(nbr, cur);
        }
    }
    tout[cur] = timer; // leave a node
    return;
}

void eulerTour_2(int cur, int par)
{
    // finally , enter exit
    cout << cur << " ";
    for (auto nbr : graph[cur])
    {
        if (nbr != par)
        {
            eulerTour_2(nbr, cur);
        }
    }
        cout << cur << " ";
    return;
}

void eulerTour_1(int cur, int par)
{
    // enter exit
    cout << cur << " ";
    for (auto nbr : graph[cur])
    {
        if (nbr != par)
        {
            eulerTour_1(nbr, cur);
            cout << cur << " ";
        }
    }
    return;
}

int main()
{
    // input
    // 9 1 2 2 4 2 5 2 6 1 3 3 7 7 8 7 9

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // cout << "Euler tour 1: ";
    // eulerTour_1(1, 0);
    // cout << endl;

    // cout << "Euler tour 2: ";
    // eulerTour_2(1, 0);
    // cout << endl;
    timer = 0;
    // cout << "Euler tour 3: ";
    eulerTour_3(1, 0);
    // cout << endl;
    for(int i = 1; i <= n; i++) {
        cout << i << " " << tin[i] << " " << tout[i] << endl;
    }
    cout << endl;

    cout << (isAncestor(3, 9) ? "Yes" : "No") << endl;

    return 0;
}