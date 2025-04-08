#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node {
public:
    Node* child[26];
    bool eow;
    int freq;

    Node() {
        eow = false;
        freq = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
    // List of inserted strings

public:
      Node* root;
    vector<string> insertedStrings; 
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        insertedStrings.push_back(s); // Store the string
        Node* tmp = root;
        for (char c : s) {
            int index = c - 'a';
            if (tmp->child[index] == NULL) {
                tmp->child[index] = new Node();
            }
            tmp->child[index]->freq++; // Increment frequency
            tmp = tmp->child[index];
        }
        tmp->eow = true;
    }

    bool search(string s) {
        Node* tmp = root;
        for (char c : s) {
            int index = c - 'a';
            if (tmp->child[index] == NULL) {
                return false;
            }
            tmp = tmp->child[index];
        }
        return tmp->eow;
    }

    string getprefix(string key) {
        Node* tmp = root;
        string prefix = "";
        for (char c : key) {
            prefix += c;
            int index = c - 'a';
            if (tmp->child[index]->freq == 1) { // Unique prefix found
                break;
            }
            tmp = tmp->child[index];
        }
        return prefix;
    }

    void prefixproblem() {
        for (string s : insertedStrings) {
            cout << "Shortest unique prefix of \"" << s << "\": " << getprefix(s) << endl;
        }
    }
    int countsubstr()
   {
    return countnode(root);
   }
   int countnode(Node*root)
   {
    if(!root) return 0;
    int cc=0;
    for(ll i=0;i<26;i++)
    {
        if(root->child[i])
        {
            cc+=countnode(root->child[i]);

        }

    }
    return cc+1;
   }
    void longesthelp(Node* currentNode, string& ans, string tmp) {
        for (int i = 0; i < 26; i++) {
            if (currentNode->child[i] != NULL) {
                tmp += (char)(i + 'a');
                if (currentNode->child[i]->eow) {
                    if ((tmp.size() == ans.size() && tmp < ans) || tmp.size() > ans.size()) {
                        ans = tmp;
                    }
                }
                longesthelp(currentNode->child[i], ans, tmp);
                tmp.pop_back(); // Backtrack
            }
        }
    }

    string longeststringeow() {
        string ans = "";
        longesthelp(root, ans, "");
        return ans;
    }
};

bool word_break(Trie &t, string key) {
    if (key.empty()) {
        return true;
    }
    for (int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i + 1);
        string second = key.substr(i + 1);
        if (t.search(first) && word_break(t, second)) {
            return true;
        }
    }
    return false;
}
int cntunqsubstr(string s)//suffix
{/// count unique substrings
    Trie t;
    for(ll i=s.size()-1;i>=0;i--)
    {
        t.insert(s.substr(i));
    }
    return t.countsubstr();
}
int main() {
    Trie t;
    t.insert("mist");
    t.insert("ant");
    t.insert("juicy");
    t.insert("dog");
    t.insert("dove");

    cout << "Searching for 'mist': " << (t.search("mist") ? "Found" : "Not Found") << endl;
    t.prefixproblem(); // Display shortest unique prefixes

    // Test word_break
    string key1 = "mistjuicy";
    string key2 = "antdog";
    string key3 = "antcat";
    cout << "Word break for 'mistjuicy': " << (word_break(t, key1) ? "Yes" : "No") << endl;
    cout << "Word break for 'antdog': " << (word_break(t, key2) ? "Yes" : "No") << endl;
    cout << "Word break for 'antcat': " << (word_break(t, key3) ? "Yes" : "No") << endl;
     string s="ababa";
   cout<<cntunqsubstr(s) <<endl;
    return 0;
}
