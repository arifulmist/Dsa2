#include<bits/stdc++.h>

using namespace std;

int counts=0;

struct Bill
{
    string name;
    int amount;
    int timestamp;
    Bill()
    {
        name="";
        amount=0;
        timestamp=0;
    }
    Bill(string n,int a,int t)
    {
        name=n;
        amount=a;
        timestamp=t;
    }
};

class PQ
{
    public:
    int heap_size;
    Bill bill[100];
    PQ()
    {
        heap_size = 0;
    }
    void heapInsert(Bill val)
    {
        heap_size++;
        bill[heap_size]=val;
        heapifyUp(heap_size);
    }
    void heapifyUp(int index)
    {
        if(index==1) return;
        if(bill[index].amount > bill[index/2].amount)
        {
            swap(bill[index],bill[index/2]);
            heapifyUp(index/2);
        }
    }

    void heapifyDown(int index) {
        int hi=index;
        int lt=2*index;
        int rit=2*index+1;
        if(bill[lt].amount > bill[hi].amount)
        {
          hi=lt;
        }
        else if(bill[rit].amount > bill[hi].amount)
        {
           hi=rit; 
        }
        else 
        {
            hi =index;
        }
        if(hi!=index)
        {
            swap(bill[index],bill[hi]);
            heapifyDown(hi);
        }
}

     void extractmax() {
        cout<<bill[1].amount<<"\n";
        int tmp=bill[1].amount;
        swap(bill[1], bill[heap_size]);
        heapifyDown(heap_size);
        heap_size--;
    }
};

int main()
{
    PQ pq;
    int tt=0;
    cout<<"Press Q to Exit\n";
    while(1)
    { 
        string s;
        cout<<"Enter Customer "<<++tt<<":\n"; 
         cout<<"Name:";
        cin >> s;
       
        if(s=="Q") break;
        cout<<"Amount:";
        int amount; cin >> amount;
        counts++;
         //pq.heapInsert(Bill(s,amount,counts));
        Bill bill=Bill(s,amount,counts);
        pq.heapInsert(bill);
    }
//    pq.extractmax();
//    pq.extractmax();
//    pq.extractmax();
    for(int i=1;i<=pq.heap_size;i++)
    {
        cout << pq.bill[i].name<<" "<<pq.bill[i].amount << " "<<pq.bill[i].timestamp<<" ";
    }


    return 0;
}

