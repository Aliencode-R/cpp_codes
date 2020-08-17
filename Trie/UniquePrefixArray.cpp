#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    int freq;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        freq = 1;
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

    void search(TrieNode *root, string word, string output)
    {
        // cout << root->data << " " << root->freq << endl;
        if (word.size() == 0)
        {   
            cout << output << endl;
            // return root->isTerminal;
            return ;
        }
        output += word[0];

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child = root->children[index];


        if(child->freq == 1) {
            cout << output << endl;
            return ;
        }
        // Recursive call
         search(child, word.substr(1), output);
    }
    void search(string word, string output)
    {
        search(root, word, output);
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
            child->freq++;
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

    void removeWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        // Small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Word not found
            return;
        }
        removeWord(child, word.substr(1));
        // Remove child Node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    void removeWord(string word)
    {
        removeWord(root, word);
    }
};

int main () { 
    int n; cin >> n;
    vector<string> v;
    Trie t;
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        v.push_back(s);
        t.insertWord(s);
    }
    for(string s: v) {
        
        t.search(s, "");
    }
    return 0;
}