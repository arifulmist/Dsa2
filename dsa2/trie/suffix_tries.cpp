#include<bits/stdc++.h>
using namespace std;
class node
{
     public:
     bool eow;
     node *child[26];
     node()
     {
         eow = false;
         for(int i=0;i<26;i++)
         {
             child[i] = nullptr;
         }
     }
};
class TRie
{
     public:
     node *root;
     TRie()
     {
        root = new node();
     }
     void insert(string txt)
     {
         node * cur = root;
         for(int i=0;i<txt.size();i++)
         {
             int j = txt[i]-'a';
             if(cur->child[j]==nullptr)
             {
                  cur->child[j] = new node();
             }
             cur = cur->child[j];
         }
         cur->eow = true;
     }
     bool find(string txt)
     {
         node *cur = root;
         for(int i=0;i<txt.size();i++)
         {
             int j = txt[i]-'a';
             if(cur->child[j]==nullptr) return false;
             cur = cur->child[j];
         }
         return cur->eow;
     }
     void print(node *cur,string s="")
     {
        if(cur->eow) cout<<s<<endl;
         for(int i=0;i<26;i++)
         {
            if(cur->child[i]!=nullptr)
            {
                char c = char(i+'a');
                print(cur->child[i],s+c);
            }
         }
     }
     bool is_suffix(string suf)
     {
          node * cur = root;
          for(int i=0;i<suf.size();i++)
          {
              int j = suf[i]-'a';
              if(cur->child[j]==nullptr) return false;
              cur = cur->child[j];
          }
          return true;
     }
};
int main()
{
    TRie tr;
    vector<string>pp = {"mist","mit","buet","bubt","cu","cuet","bup"};
    for(int i=0;i<pp.size();i++)
    {
        reverse(pp[i].begin(),pp[i].end());
        tr.insert(pp[i]);
    }
    vector<string>suf = {"ts","u","tb","pu"};
    for(int i=0;i<suf.size();i++)
    {
         cout<<suf[i]<<" --> "<<tr.is_suffix(suf[i])<<endl;
    }
   // tr.print(tr.root);
}