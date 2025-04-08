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
     void helper(node *cur,string &tmp,vector<string>&doc)
     {
         if(cur->eow) doc.push_back(tmp);
         for(int i=0;i<26;i++)
         {
            if(cur->child[i]!=nullptr && cur->child[i]->eow)
            {
                 tmp+=char(i+'a');
                 helper(cur->child[i],tmp,doc);
                 tmp.pop_back();
             }
         }
     }
     string ll_w()
     {
          node *cur = root;
          string tmp = "";
          vector<string>doc;
          helper(cur,tmp,doc);
          int mx =INT_MIN;
          for(auto x:doc)
          {
               int a = x.size();
               mx = max(mx,a);
          } 
          vector<string>st;
          for(auto x:doc)
          {
             int a = x.size();
             if(a==mx) st.push_back(x);
          }
          sort(st.begin(),st.end());
          return st[0];
     }
};
int main()
{
    TRie tr;
    vector<string>pp = {"a","banana","app","appl","ap","apply","apple"};
    for(int i=0;i<pp.size();i++)
    {
        tr.insert(pp[i]);
    }
    cout<<tr.ll_w()<<endl;
}