#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    TrieNode *search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return NULL;
        }
        // Recursive call
        return search(child, word.substr(1));
    }
    TrieNode *search(string word)
    {
        return search(root, word);
    }

    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }
    // For user
    void insertWord(string word)
    {
        insertWord(root, word);
    }

    void helper(TrieNode *root, string output)
    {
        // output += root
        // output += root->data;
        if (root->isTerminal == true)
        {
            cout << output << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                char ch = i + 'a';
                helper(root->children[i], output + ch);
            }
        }
        return;
    }
};

int main()
{
    int n;
    cin >> n;
    string arr[n];
    Trie t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        t.insertWord(arr[i]);
    }
    int m;
    cin >> m;
    while (m--)
    {

        string toFind;
        cin >> toFind;
        TrieNode *a = t.search(toFind);
        if (a == NULL)
        {
            cout << "No suggestions" << endl;
            continue;
            // return 0;
        }
        t.helper(a, toFind);
    }

    return 0;
}