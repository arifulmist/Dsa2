#include<bits/stdc++.h>

using namespace std;

struct Node{
    bool EoW;
    Node* children[26];
};

Node* root;

Node* createNode()
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->EoW=false;
    for(int i=0;i<26;i++){
        n->children[i]=NULL;
    }
    return n;
}

void insert(string s){
    Node* cur = root;
    for(int i=0;i<s.size();i++){
        int j = s[i] - 'a';
        if(cur->children[j]==NULL){
            cur->children[j] = createNode();
        }
        cur = cur->children[j];
    }
    cur->EoW = true;
}

void printTRIE(Node* cur=root,string s=""){
    if(cur->EoW)
    {
        cout << s << endl;
    }
    for(int i=0;i<26;i++){
        if(cur->children[i]==NULL) continue;
        char ch = i + 'a';
        printTRIE(cur->children[i],s+ch);
    }
}

bool find(string s){
    Node* cur = root;

    for(int i=0;i<s.size();i++){
        int j = s[i] - 'a';
        if(cur->children[j]==NULL){
            return false;
        }
        cur = cur->children[j];
    }
    return cur->EoW;
}

bool isLeaf(Node* cur)
{
    bool ret = 1;
    for(int i=0;i<26;i++)
    {
        if(cur->children[i]!=NULL) ret = 0;
    }
    return ret;
}

bool isJunction(Node* cur) /// true means stop deleting
{
    if(cur->EoW) return true;
    if(isLeaf(cur)) return false;
    return true;
}

void removeEdge(Node *u, char c, int d){
    if(d==0) return;
    int j = c - 'a';
    Node *v = u->children[j];
    u->children[j] = NULL;
    free(v);
}

int deleteNode(string s,Node* cur=root,int i=0)
{
    if(cur==NULL) return 0;
    if(i==s.size())
    {
        if(cur->EoW==0) return 0;
        if(isLeaf(cur)==false){
            cur->EoW = 0;
            return 0;
        }
        return 1;
    }
    int j=s[i]-'a';
    int d = deleteNode(s,cur->children[j],i+1);
    removeEdge(cur,s[i],d);
    if(isJunction(cur)) d=0;
    return d;
}


int main(){
    root = createNode();

    insert("mist");
    insert("bubt");
    insert("buet");
    insert("mit");
    insert("mi");
    insert("cu");
    insert("exam");
    insert("exit");

    printTRIE();

    //cout << "mi " << find("mi") << endl;
    //cout << "mit " << find("mit") << endl;
    cout << "mist " << find("mist") << endl;
    //cout << "mis " << find("mis") << endl;
    //cout << "cuet " << find("cuet") << endl;

    deleteNode("mist");
    cout << "mist " << find("mist") << endl;

    printTRIE();

    free(root);

    return 0;
}
