#include <bits/stdc++.h>
using namespace std;
#define ll long long

void build_tree(int *arr, int *tree, int start, int end, int treenode)
{
    if(start == end)
    {
        tree[treenode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build_tree(arr,tree,start,mid,2*treenode);
    build_tree(arr,tree,mid+1,end,2*treenode+1);

    tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
    return ;
}

void update_tree(int *arr, int *tree, int start, int end, int treenode, int index,int value)
{
    if(start == end)
    {
        arr[start] = value;
        tree[treenode] = value;
        return;
    }
    int mid = (start+end)/2;
    if(index > mid)
    {
        update_tree(arr, tree, mid+1, end, 2*treenode+1, index, value);
    }
    else
    {
        update_tree(arr, tree, start, mid, 2*treenode, index, value);
    }
    tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
}
int query_tree(int *arr, int *tree, int start, int end, int treenode, int left, int right)
{
    if(start > right || end < left)
    {
        return 0;
    }
    if(start >= left && end <= right)
    {
        return tree[treenode];
    }
    int mid = (start+end)/2;
    int ans1 = query_tree(arr, tree, start, mid, 2*treenode, left, right);
    int ans2 = query_tree(arr, tree, mid+1, end, 2*treenode+1, left, right);
    return ans1+ans2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tree[4*n];
    memset(arr,0,sizeof(arr));
    build_tree(arr,tree,0,n-1,1);
    update_tree(arr,tree,0,n-1,1,5,12);
    query_tree(arr, tree, 0, n-1, 1, 4, 7);

    return 0;
}