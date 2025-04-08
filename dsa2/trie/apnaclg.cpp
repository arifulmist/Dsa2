#include<bits/stdc++.h>
using namespace std;
#define ll long long 
class node{
public:
bool eow;
map<char,node*>child;
int freq;
node()
{
    eow=false;
}
};
class Trie{
     node* root;
     vector<string >sto;
    public:
   
    Trie()
    {
        root=new node();
        root->freq=-1;
    }
    void insert(string s)
    {
        sto.push_back(s);
        node* tmp=root;
        for(ll i=0;i<s.size();i++)
        {
            if(tmp->child.count(s[i])==0)
            {
                tmp->child[s[i]]=new node();
                tmp->child[s[i]]->freq=1;
            }
            else{
                tmp->child[s[i]]->freq++;

            }
            tmp=tmp->child[s[i]];
        }
        tmp->eow=true;
    }
    bool search(string s)
    {
       node* tmp=root;
        for(ll i=0;i<s.size();i++)
        {
            if(tmp->child.count(s[i]))
            {
               tmp=tmp->child[s[i]];
            }
            else return false;
        }
                  return tmp->eow;   
   }
    
    string getprefix(string key)
    {
        node* tmp=root;
        string prfix="";
        for(ll i=0;i<key.size();i++)
        {
            prfix+=key[i];
            if(tmp->child[key[i]]->freq==1)
            {
                break;
            }
            tmp=tmp->child[key[i]];
        }
        return prfix;
    }
    void prefixproblem()
   {
    for(auto i:sto )
    {
        cout<<getprefix(i)<<endl;
    }
   }
   bool startwith(string pre)
   {
    node* tmp=root;
    for(ll i=0;i<pre.size();i++)
    {
        if(tmp->child[pre[i]])
        {
          tmp=tmp->child[pre[i]];
        }
        else 
        {
            return false;
        }
    }
    return true;
   }
   int countDistinctSubstrings() {
        return countNodes(root);
    }
    int countNodes(node* currentNode) {
        if (!currentNode) return 0;

        int count = 0;
        for (auto& child : currentNode->child) {
            count += countNodes(child.second); // Recurse for all children
        }
        return count + 1; // Count this node
    }
    void longesthelp(node* root,string &ans,string tmp)
    {
        for(pair<char,node*>chid:root->child)
        {
            if(chid.second->eow)
            {
                tmp+=chid.first;
                if((tmp.size()==ans.size()&&tmp<ans)||(tmp.size()>ans.size()))
                {
                    ans=tmp;
                }
                longesthelp(chid.second,ans,tmp);
                tmp=tmp.substr(0,tmp.size()-1);
            }
        }
    }
    string longeststringeow()
    {
        string ans="";
        longesthelp(root,ans,"");
        return ans;
    }
};

bool word_break(Trie & t,string key)
{
    if(key.size()==0)
    {
        return true;
    }
    for(ll i=0;i<key.size();i++)
    {
        string first=key.substr(0,i+1);
        string second=key.substr(i+1);
        if(t.search(first)&& word_break(t,second))
        {
            return true;
        }
    }
    return false;
}
int countDistinctSubstrings(const string& s) {
    Trie t;
    // Insert all suffixes
    for (ll i = s.size() - 1; i >= 0; i--) {
        t.insert(s.substr(i));
    }
    return t.countDistinctSubstrings() ; // Exclude the root node
}
int main()
{
     Trie t;
     t.insert("zebra");
     t.insert("duck");
     t.insert("ant");
     t.insert("dog");
     t.insert("dove");
     t.insert("a");
     t.insert("app");
     t.insert("appl");
     t.insert("ap");
     cout<<t.longeststringeow();
     //t.prefixproblem();
//    string s="ababa";
//    cout<<countDistinctSubstrings(s) <<endl;

    //cout<< t.startwith("z");
    //   cout<< t.search("mist")<<endl;
    // cout<<word_break(t,"mistjucy")<<"\n";

    
}