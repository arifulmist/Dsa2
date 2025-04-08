#include<bits/stdc++.h>
using namespace std;
struct node
{
  bool eow;
  node *child[26];
};
node *root;
node* createnode()
{
    node*n=(node*)malloc(sizeof(node));
    n->eow=false;
    for(int i=0;i<26;i++)
    {
        n->child[i]=NULL;
    }
    return n;
}
void insert(string s)
{
 node* cur=root;
 for(int i=0;i<s.size();i++)
 {
    int ind=s[i]-'a';
    if(cur->child[ind]==NULL)
    {
        cur->child[ind]=createnode();
    }
    cur=cur->child[ind];
 }
 cur->eow=true;
}
void  printTRIE(node * cur=root,string s=" ")
{
     if(cur->eow)
     {
        cout<<s<<"\n";
        
     }
    for(int i=0;i<26;i++)
    {
       if(cur->child[i]==NULL)
       {
         continue;
       }
       char ch=i+'a';
       printTRIE(cur->child[i],s+ch);
    }
}
bool find(string s)
{
 node* cur=root;
 for(int i=0;i<s.size();i++)
 {
    int ind=s[i]-'a';
    if(cur->child[ind]==NULL)
    {
        return false;
    }
    cur=cur->child[ind];
 }
   return cur->eow;
}
int deletenode(string s,node* cur=root,int i=0)
{
    if(cur==NULL) return 0;
    if(i==s.size())
    {
        if(cur->eow==false) return 0;
        if(isleaf(cur)==false)
        {
            cur->eow=0;
            return 0;
        }
        return 1;
    }
    int ind=s[i]-'a';
    int del=deletenode(s,cur->child[ind],i+1);
    removeedge(cur,s[i],d);
    if(isjunction(cur)) d=0;
    return d;
}
bool leaf(node*cur)
{
   bool ret=true;
   for(int i=0;i<26;i++)
   { 
    if(cur->child[i]!=NULL) ret=false;
   }
   return ret;
}
bool isjunction(node*cur)
{
    if(cur->eow) return true;
    if(isleaf(cur)) return false;
    return true; 
}
int main()
{
    root=createnode();
    insert("mist");
    insert("bubt");
    insert("buet");
    insert("mit");
    insert("cu");
    insert("exam");
    insert("exit");
    printTRIE();
    cout<<"mist"<<" "<<find("mist");
    cout<<"bubt"<<" "<<find("bubt");
       cout<<"mis"<<" "<<find("mis");
       cout<<"buet"<<" "<<find("buet");
       cout<<"co"<<" "<<find("co");
    //node er under a sob substring 
   //hw          //count kora lagbe 
}