#include<bits/stdc++.h>
using namespace std;
#define ll long long
class node{
public:
int freq;
bool flag;
node* arr[4];
node()
{
    freq=0;
    flag=false;
    for(ll i=0;i<4;i++)
    {
        arr[i]=NULL;
    }
}
};
class Trie{
    private:
     node* root;
    int mx;
    void longesthelp(node* cur, string& ans, string tmp) {
        if(cur==NULL) return ;

        for (int i = 0; i < 4; i++) 
        {
            if (cur->arr[i]!=NULL)
             {
               
                if(i==0)
                {
                      tmp +='A';
                }
                else if(i==1)
                {
                    tmp+="C";
                }
                else if(i==2)
                {
                    tmp+="G";
                }
                else 
                {
                    tmp+="T";
                }
                if (cur->arr[i]->freq==mx) {
                    if ((tmp.size() == ans.size() && tmp < ans) || tmp.size() > ans.size()) {
                        ans = tmp;
                    }
                }
                longesthelp(cur->arr[i], ans, tmp);
                tmp.pop_back();
            }
        }
    }
    public:
   
    Trie()
    {
        root=new node();
        mx=0;
    }
    void insert(string s)
    {
        node* tmp=root;
      for(auto i:s)
      {
        int ind;
        if(i=='A')
        {
            ind=0;
        }
        else if(i=='C')
        {
            ind=1;
        }
        else if(i=='G')
        {
            ind=2;
        }
        else if(i=='T')
        {
            ind=3;
        }
        if(tmp->arr[ind]==NULL)
        {
            tmp->arr[ind]=new node();
        }
        tmp->arr[ind]->freq++;
        mx=max(mx, tmp->arr[ind]->freq);
        tmp=tmp->arr[ind];
      }
      tmp->flag=true;
    }
     
    string longeststringeow() {
        string ans = "";
        node *rt=root;
        longesthelp(rt, ans, "");
        return ans;
    }
};

int main()
{
int t,x;
cin>>t;
Trie tt;
while(t--)
{
    cin>>x;
    if(x==1)
    {
        string s;
        cin>>s;
        tt.insert(s);
    }
    else 
    {
       cout<< tt.longeststringeow()<<"\n";
    }
}


}
