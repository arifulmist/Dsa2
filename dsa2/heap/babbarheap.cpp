#include<bits/stdc++.h>
using namespace std;
class heap
{
public:
int arr[100];
int size;
heap()
{
    arr[0]=-1;
    size=0;
}
void insert(int val)//t.c O(logn)
{
  size++;
  int ind=size;
  arr[ind]=val;
  while(ind>1)
  {
    int par=ind/2;
    if(arr[par]<arr[ind])
    {
        swap(arr[par],arr[ind]);
        ind=par;
    }
    else 
    {
        return;
    }
  }
}
void print()
{
    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void deletee()
{
    if(size==0)
    {
        return ;

    }
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size)
    {
        int left=2*i;
        int right=2*i+1;
        if(left<size &&arr[i]<arr[left])
        {
            i=left;

        }
        else if(right<size &&arr[i]<arr[right])
        {
            i=right;

        }
        else 
        {
            return ;
        }
    }
}

};
void heapify(int arr[],int n,int i)//O(logn)
{
 int lar=i;
 int left=2*i;
        int right=2*i+1;
        if(left<=n&&arr[lar]<arr[left])
        {
            lar=left;

        }
         if(right<=n &&arr[lar]<arr[right])
        {
            lar=right;

        }
   if(lar!=i)
   {
    swap(arr[lar],arr[i]);
    heapify(arr,n,lar);
   }
}
void minheapify(vector<int>& arr,int n,int i)//O(logn)
{
 int smal=i;
 int left=2*i;
int right=2*i+1;
        if(left<=n&&arr[smal]>arr[left])
        {
            smal=left;

        }
         if(right<=n &&arr[smal]>arr[right])
        {
            smal=right;

        }
   if(smal!=i)
   {
    swap(arr[smal],arr[i]);
    minheapify(arr,n,smal);
   }
}
void heapsort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main()
 {
     heap hp;
     hp.insert(50);
      hp.insert(54);
       hp.insert(55);
       hp.print();
       hp.deletee();
       hp.print();
      int arr[6]={-1,54,53,55,52,50};
      int n=5;
      for(int i=n/2;i>0;i--)
      {
        heapify(arr,n,i);
      } 

      for(int i=1;i<=n;i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<"\n";
      heapsort(arr,n);
      for(int i=1;i<=n;i++)
      {
        cout<<arr[i]<<" ";
      }


}