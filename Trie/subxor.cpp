#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left;  // 0
    node *right; // 1
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }
    // insert function
    void insert(int n)
    {
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    // helper func to find max xor for the value and all the elements entered up untill now
    int maxXorHelper(int value)
    {
        int cur = 0;
        node *temp = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (value >> j) & 1;

            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    cur += (1 << j);
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    cur += (1 << j);
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        cout << cur << " ";
        return cur;
    }
};

int main() {

    int n; cin >> n;
    int result = 0;
    int arr[n];
    int lbest[100000], rbest[100000];
    int lval = 0, rval = 0;

    trie tl;
    tl.insert(0); // for single elements xor
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        lval ^= arr[i];
        lbest[i] = max((i == 0) ? 0 : lbest[i-1], tl.maxXorHelper(lval));
        tl.insert(lval);
    }
    trie tr;
    tr.insert(0);
    for(int i = n-1; i >= 0; i--) {
        rval ^= arr[i];
        rbest[i] = max((i == n-1) ? 0 : rbest[i+1], tr.maxXorHelper(rval));
        tr.insert(rval);
    }
    for(int i = 0; i < n; i++) {
        int val = lbest[i] + (i == n-1 ? INT_MIN : rbest[i+1]);
        result = max(result, val);
    }
    cout << result ;


    return 0;
}