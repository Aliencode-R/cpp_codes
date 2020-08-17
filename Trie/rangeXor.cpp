#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left;    //Left child node denotes 0 bit
    node *right;   //Right child node denotes 1 bit
    vector<int> v; //Vector to contain all the indices of which this bit is a part of at ith place
    node()
    {
        left = right = NULL;
    }
};

class trie {
    node *root;
public :
    trie() {
        root = new node();
    }

    void insert(int n, int index) {
        node *temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(bit == 0) {
                if(temp->left == NULL) {
                    temp->left = new node();
                }
                temp->v.push_back(index);
                temp = temp->left;                
            } else {
                if(temp->right == NULL) {
                    temp->right = new node();
                }
                temp->v.push_back(index);
                temp = temp->right;
            }
        }
        temp->v.push_back(index);
    }
    int maxXor(int value, int left, int right) {
        int curxor = 0;
        node* temp = root;
        for(int j = 31; j >= 0; j--) {
            int bit = (value >> j) & 1;
            if(bit == 0) {
                if(temp->right != NULL and binarySearchRange(temp->right->v, left, right)) {
                    temp = temp->right;
                    curxor += (1 << j);
                } else {
                    temp = temp->left;
                }
            }
            else
            {
                //Value has 1 bit at jth pos , move left if possible
                if (temp->left != NULL && binarySearchRange(temp->left->v, left, right))
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                    curxor += (1 << j); //Add the number with jth bit set to the currentXor
                }
            }
        }
        return curxor;
    }

    bool binarySearchRange(vector<int> v, int l, int r)
    {
        //Vector v has indices stored of the numbers of which this bit is a part of
        //Since the insertion took place in increasing order , vector is already sorted
        int s = 0;
        int e = v.size() - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int val = v[mid];
            if (val >= l && val <= r)
            {
                return true;
            }
            else if (val < l)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return false;
    }

};

int main () {
    int q; cin >> q;
    trie t;
    int index = 0;
    while(q--) {
        int type; cin >> type;
        if(type == 0) {
            int x; cin >> x;
            t.insert(x, index++);
        } else {
            int l, r, x; cin >> l >> r >> x;
            cout << t.maxXor(x, l-1, r-1) << endl;
        }
    }
    return 0;
}