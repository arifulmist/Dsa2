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