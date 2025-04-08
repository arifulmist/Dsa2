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
     int node_cnt(node *cur,int cnt)
     {
          for(int i=0;i<26;i++)
          {
               if(cur->child[i]!=nullptr)
               {
                   cnt++;
                   cnt = node_cnt(cur->child[i],cnt);
               }
          }
          return cnt;
     }
};
int main()
{
    TRie tr;
    string txt;
    cin>>txt;
    int n = txt.size();
    vector<string>suf;
    string tmp = "";
    for(int i=n-1;i>=0;i--)
    {
        tmp+=txt[i];
        string tnp = tmp;
        reverse(tnp.begin(),tnp.end());
        suf.push_back(tnp);
    }
    for(int i=0;i<suf.size();i++)
    {
        tr.insert(suf[i]);
    }
    cout<<tr.node_cnt(tr.root,0)+1<<endl;
}