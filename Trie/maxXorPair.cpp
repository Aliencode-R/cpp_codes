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
    // linearly traverses the array and puts the element in trie
    int maxXor(int *input, int n) {
        int MaxXor = INT_MIN;
        for (int i = 0; i < n; i++) {
            int val = input[i];
            insert(val);
            int cur = maxXorHelper(val);
            MaxXor = max(MaxXor, cur);
        }
        cout << endl;
        return MaxXor;
    }

};

int main()
{
    int n; cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];

    trie t;
    // cout << t.maxXor(input, n); // max xor pair

    // for max xor sub array , we make cumilative xor array and 
    // find l,r as same we did for xor pair , simple :)

    int cumXor[n];
    cumXor[0] = input[0];

    for (int i = 1; i < n; i++) {
        cumXor[i] = input[i]^cumXor[i-1];
    }
    cout << t.maxXor(cumXor, n);

    return 0;
}