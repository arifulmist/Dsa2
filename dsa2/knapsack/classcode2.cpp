#include<bits/stdc++.h>
using namespace std;
struct item
{
    int ser;
   int val;
   int weig;
   float ratio;
   item(int val,int weig,int ser)
   {
    this->val=val;
    this->weig=weig;
    this->ratio=(float)val/weig;
    this->ser=ser;
   }
};
bool cmp(item &a,item &b)
{
   return a.ratio>b.ratio;
}
void printitems(vector<int>v,vector<int>w)
{
    for(auto i:iteams)
    {
        cout<+<<"\n";
    }
}
float fractionalknapsack(int n,int w,vector<item>&items)
{
    sort(items.begin(),items.end(),cmp);
    printitems(items);
    float pro;
    for(int i=0;i<items.size();i++)
    {
        if(w>items[i].weig)
        {
          pro+=items[i].val;
          w-=items[i].weig;
          cout<<"taking"<<items[i].ser<<"th item of weight:"<<items[i].weig<<" "<<items[i].val<<" "<<"\n";
        }
        else 
        {
            pro+=(w*items[i].ratio);
           // w-=w;
            cout<<"taking"<<items[i].ser<<"th item of weight:"<<w<<" "<<w*items[i].ratio<<"\n";
            break;
        }
    }
    return pro;
}
int main()
{
           
int n,w;
cout << "Enter the number of items: ";
cin >> n;
cout<<"ENTER the size of knapsak";
cin>>w;
vector<int >values;
vector<int>weight;

for (int i = 0; i < n; i++)
 {
    int val, weig;
    cout << "Enter value and weight for item " << i + 1 << ": ";
    cin >> val >> weig;
    values.push_back(val);
    weight.push_back(weig);
}
printitems(items);

float lav=fractionalknapsack(n,w,items);
cout<<lav;
}
/*
#include <bits/stdc++.h>
using namespace std;

Weight: 2 3 4 5
Value: 1 3 5 3
Limitation: 8Kg

int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
        return 0;
    if (weight[n - 1] <= W)
    {
        // duita option
        // niye dekhbo, na niye dekhbo
        int op1 = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];
        int op2 = knapsack(n - 1, weight, value, W);
        return max(op1, op2);
    }
    else
    {
        // ekta option
        // na niyei dekhte hobe
        int op2 = knapsack(n - 1, weight, value, W);
        return op2;
    }
}
int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int W;
    cin >> W;
    cout << knapsack(n, weight, value, W) << endl;
    return 0;
}
*/