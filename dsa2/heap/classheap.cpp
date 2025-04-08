#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

// Bill class representing a customer's bill
class Bill
{
public:
    char name[50]; // Customer's name
    int amount;    // Bill amount
    int timestamp; // Timestamp to handle tie-breaking

    // Default constructor
    Bill()
    {
        strcpy(this->name, "");
        this->amount = 0;
        this->timestamp = 0;
    }

    // Parameterized constructor
    Bill(char name[50], int amount = 0, int timestamp = 0)
    {
        strcpy(this->name, name);
        this->amount = amount;
        this->timestamp = timestamp;
    }
      bool operator==(const Bill& other) const
   {
      return (strcmp(this->name, other.name) == 0 &&
            this->amount == other.amount &&
            this->timestamp == other.timestamp);
   }
};

// Priority Queue class
class PriorityQueue
{
private:
    Bill heap[MAX_SIZE]; // Array for the max-heap
    Bill heapmn[MAX_SIZE]; // Array for the min-heap
    int size_;           // Current number of elements in the heap
    int counter = 0;
    // Utility function to swap two bills
    void swap_(Bill &a, Bill &b)
    {
        Bill temp = a;
        a = b;
        b = temp;
    }

    // Heapify up to maintain max-heap property
    void heapifyUp(int index, char *A, int a, int cnt)
    {
        heap[index].amount = a;
        strcpy(heap[index].name, A);
        heap[index].timestamp = cnt;
        while (index > 1 && heap[index / 2].amount < heap[index].amount)
        {
            swap(heap[index / 2], heap[index]);
            index /= 2;
        }
    }
    void heapifyUpmn(int index, char *A, int a, int cnt)
    {
        heapmn[index].amount = a;
        strcpy(heapmn[index].name, A);
        heapmn[index].timestamp = cnt;
        while (index > 1 && heapmn[index / 2].amount > heapmn[index].amount)
        {
            swap(heapmn[index / 2], heapmn[index]);
            index /= 2;
        }
    }

    // Heapify down to maintain max-heap property
    void heapifyDown(int index)
    {
        int l = index * 2;
        int r = index * 2 + 1;
        int largest = index;
        if (l <= size_ && heap[l].amount >= heap[largest].amount)
        {
            if(heap[l].amount == heap[largest].amount)
            {
                if(heap[l].timestamp<heap[largest].timestamp)
                {
                    largest = l;
                }
            }
            else
            largest = l;
        }
        if (r <= size_ && heap[r].amount >= heap[largest].amount)
        {
            if(heap[r].amount == heap[largest].amount)
            {
                if(heap[r].timestamp<heap[largest].timestamp)
                {
                    largest = r;
                }
            }
            else
            largest = r;
        }
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
     void heapifyDownmn(int index)
    {
        int l = index * 2;
        int r = index * 2 + 1;
        int smallest = index;
        if (l <= size_ && heapmn[l].amount <= heapmn[smallest].amount)
        {
            if(heapmn[l].amount == heapmn[smallest].amount)
            {
                if(heapmn[l].timestamp<heapmn[smallest].timestamp)
                {
                    smallest = l;
                }
            }
            else
            smallest = l;
        }
        if (r <= size_ && heapmn[r].amount <= heapmn[smallest].amount)
        {
            if(heapmn[r].amount == heapmn[smallest].amount)
            {
                if(heapmn[r].timestamp<heapmn[smallest].timestamp)
                {
                    smallest = r;
                }
            }
            else
            smallest = r;
        }
        if (smallest != index)
        {
            swap(heapmn[index], heapmn[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Constructor
    PriorityQueue()
    {
        size_ = 0;
    }

    // Add a bill to the priority queue
    void addBill(char *name, int amount, int timestamp)
    {
        size_++;
        heapifyUp(size_, name, amount, timestamp);
        heapifyUpmn(size_,name,amount,timestamp);
    }
    int find_min(Bill k,int idx)
    {
         int l = 2*idx;
         int r = 2*idx+1;
         if(l>size_ && r>size_) return -1;
         if(heapmn[l]==k) return l;
         if(heapmn[r]==k) return r;
         int ls = find_min(k,l);
         int rs = find_min(k,r);
         if(ls!=-1)
         {
             return ls;
         }
         else if(rs!=-1) return rs;
         else return ls;
    }
    void find_min_idx(int k,int idx,int &i,int &ts)
    {
         int l = 2*idx;
         int r = 2*idx+1;
         if(l>size_ && r>size_) return;
         if(heapmn[l].amount==k && heapmn[l].amount==k)
         {
            if(heapmn[l].timestamp<ts && heapmn[r].timestamp<ts && heapmn[l].timestamp<heapmn[r].timestamp)
            {
                i = l;
                ts = heapmn[l].timestamp;
            }
            else if(heapmn[l].timestamp<ts && heapmn[r].timestamp<ts && heapmn[l].timestamp>heapmn[r].timestamp)
            {
                i = r;
                ts = heapmn[r].timestamp;
            }
         }
         if(heapmn[l].amount==k)
         {
             if(heapmn[l].timestamp<ts)
             {
                 i = l;
                 ts = heapmn[l].timestamp;
             }
         }
         if(heapmn[r].amount==k)
         {
             if(heapmn[r].timestamp<ts)
             {
                 i = r;
                 ts = heapmn[r].timestamp;
             }
         }
         find_min_idx(k,l,i,ts);
         find_min_idx(k,r,i,ts);
    }
    int find_max(Bill k,int idx)
    {
         int l = 2*idx;
         int r = 2*idx+1;
         if(l>size_ && r>size_) return -1;
         if(heap[l]==k) return l;
         if(heap[r]==k) return r;
         int ls = find_max(k,l);
         int rs = find_max(k,r);
         if(ls!=-1)
         {
             return ls;
         }
         else if(rs!=-1) return rs;
         else return ls;
    }
    void find_max_idx(int k,int idx,int &i,int &ts)
    {
         int l = 2*idx;
         int r = 2*idx+1;
         if(l>size_ && r>size_) return;
         if(heap[l].amount==k && heap[l].amount==k)
         {
            if(heap[l].timestamp<ts && heap[r].timestamp<ts && heap[l].timestamp<heap[r].timestamp)
            {
                i = l;
                ts = heap[l].timestamp;
            }
            else if(heap[l].timestamp<ts && heap[r].timestamp<ts && heap[l].timestamp>heap[r].timestamp)
            {
                i = r;
                ts = heap[r].timestamp;
            }
         }
         if(heap[l].amount==k)
         {
             if(heap[l].timestamp<ts)
             {
                 i = l;
                 ts = heap[l].timestamp;
             }
         }
         if(heap[r].amount==k)
         {
             if(heap[r].timestamp<ts)
             {
                 i = r;
                 ts = heap[r].timestamp;
             }
         }
         find_max_idx(k,l,i,ts);
         find_max_idx(k,r,i,ts);
    }
    // Process the highest-priority bill
    void processBill()
    {
        if (size_ == 0)
        {
            cout << "No bills to process." << endl;
            return;
        }
        if(counter==2)
        {
            Bill mn = heapmn[1];
            int idx = 1;
            int ts = INT_MAX;
            find_max_idx(heapmn[1].amount,1,idx,ts);
            //cout<<idx<<endl;
            swap(heap[idx],heap[size_]);
            swap(heapmn[1],heapmn[size_]);
            size_--;
            heapifyDown(1);
            heapifyDownmn(1);
            counter = 0;
            cout<<mn.name<<" "<<mn.amount<<" "<<mn.timestamp<<endl;
        }
        else
        {
            Bill max = heap[1];
            int idx  = 1;
            int ts = INT_MAX;
            find_min_idx(heap[1].amount,1,idx,ts);
            swap(heapmn[idx],heapmn[size_]);
            swap(heap[1], heap[size_]);
            size_--;
            heapifyDown(1);
            heapifyDownmn(1);
//            cout<<endl;
//            mnprint();
//            cout<<endl;
//            cout<<endl;
//            mxprint();
//            cout<<endl;
            cout<<max.name<<" "<<max.amount<<" "<<max.timestamp<<endl;
            counter++;
        }
    }

    // Peek the highest-priority bill
    void peekBill()
    {
        auto mx = heap[1];
        cout<<mx.name<<" "<<mx.amount<<" "<<mx.timestamp<<endl;
    }
    void mnprint()
    {
        for(int i=1;i<=size_;i++)
        {
            cout<<heapmn[i].amount<<" "<<heapmn[i].name<<" "<<heapmn[i].timestamp<<endl;
        }
    }
    void mxprint()
    {
        for(int i=1;i<=size_;i++)
        {
            cout<<heap[i].amount<<" "<<heap[i].name<<" "<<heap[i].timestamp<<endl;
        }
    }
    void update(int amnt,char *A,int ts)
    {
        Bill tmp(A,amnt,ts);
        int idx = find_max(tmp,1);
        int idx1 = find_min(tmp,1);
        heapifyUp(idx,A,amnt,ts);   
    }
    // Bill extractMax()
    // {
    //     if (size_ == 0)
    //         return NULL;
    //     Bill max = heap[1];
    //     swap(heap[1], heap[size_]);
    //     size_--;
    //     heapifyDown(1);
    //      cout << max.amount;
    //     return max;
    // }
};

int main()
{
    PriorityQueue pq;

    // Simulate timestamps
    int timestamp = 0;

    // Add bills
    pq.addBill("Alice", 200, ++timestamp);
    pq.addBill("Bob", 100, ++timestamp);
    pq.addBill("Charlie", 300, ++timestamp);
    pq.addBill("Dave", 200, ++timestamp);
    //pq.mnprint();
    // Peek the highest-priority bill
    // pq.peekBill();

    // Process bills
    pq.processBill();
    pq.processBill();
    pq.processBill();
    pq.processBill();
    // pq.extractMax();

    // Try to process an empty queue
    pq.processBill();

    return 0;
}
