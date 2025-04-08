#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Node
{
public:
    Node *child[26];
    bool eow;
    Node()
    {
        eow = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *curr = root;
        for (auto c : word)
        {
            int idx = c - 'a';
            if (curr->child[idx] == NULL)
                curr->child[idx] = new Node();
            curr = curr->child[idx];
        }
        curr->eow = true;
        cout << "inserted " << word << endl;
    }
    void print(Node *curr, string s = "")
    {
        if (curr->eow == true)
        {
            cout << s << endl;
        }
        for (int i = 0; i < 26; i++)
        {
            if (curr->child[i] != NULL)
            {
                char nextChar = i + 'a';
                print(curr->child[i], s + nextChar);
            }
        }
    }
    bool search(string word)
    {
        Node *curr = root;
        for (auto c : word)
        {
            int idx = c - 'a';
            if (curr->child[idx] == NULL)
            {
                return false;
            }
            curr = curr->child[idx];
        }
        return curr->eow;
    }
    int delHelper(string word, Node *curr, int currSize)
    {
        if (curr == NULL)
            return 0;
        if (currSize == word.size())
        {
            if (curr->eow == false)
                return 0;
            if (isLeaf(curr) == false)
            {
                curr->eow = false;
                return 0;
            }
            return 1;
        }
        int idx = word[currSize] - 'a';
        int flag = delHelper(word, curr->child[idx], currSize + 1);
        if (flag == 1)
        {
            removeEdge(curr, word[currSize], flag);
        }
        if (isJunction(curr))
            return 0;
        return flag;
    }
    bool isLeaf(Node *curr)
    {
        for (int i = 0; i < 26; i++)
        {
            if (curr->child[i] != NULL)
                return false;
        }
        return true;
    }
    bool isJunction(Node *curr)
    {
        if (curr->eow == 1)
            return true;
        if (isLeaf(curr))
            return false;
        return true;
    }
    void removeEdge(Node *curr, char c, int flag)
    {
        if (flag == 0)
            return;
        int idx = c - 'a';
        Node *del = curr->child[idx];
        curr->child[idx] = NULL;
        delete del;
    }
    int deleteWord(string word)
    {
        return delHelper(word, root, 0);
    }
};

int main()
{
    Trie t;
    t.insert("apple");
    t.insert("ape");
    t.insert("app");
    t.insert("bag");
    t.insert("bad");
    t.insert("mist");
    t.insert("apps");
    t.print(t.root);
    string word = "apple";
    if (t.search(word))
        cout << "FOUND " << word << endl;
    else
        cout << "DID NOT FOUND " << word << endl;
    t.deleteWord("apple");
    t.print(t.root);
    if (t.search(word))
        cout << "FOUND " << word << endl;
    else
        cout << "DID NOT FOUND " << word << endl;
    t.deleteWord("app");
    t.print(t.root);
}