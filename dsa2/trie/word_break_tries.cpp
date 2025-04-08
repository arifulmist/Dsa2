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
     bool rec_find(string key)
     {
        if(key.size()==0) return true;
         for(int i=0;i<key.size();i++)
         {
             string first = key.substr(0,i+1);
             string second = key.substr(i+1);
             if(find(first) && rec_find(second)) return true;
         }
         return false;
     }
};
int main()
{
    TRie tr;
    vector<string>pp = {"mist","mit","buet","bubt","cu","cuet"};
    for(int i=0;i<pp.size();i++)
    {
        tr.insert(pp[i]);
    }
    string key;
    cin>>key;/// try with mitcububt
    cout<<tr.rec_find(key)<<endl;;
}