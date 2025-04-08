#include<bits/stdc++.h>
using namespace std;
class bill
{
    string name;
int bil;
int cc;

public:
bill()
{

}
 bill(string name,int bil,int cc)
 {
    this->name=name;
    this->bil=bil;
    this->cc=cc;
 }
 void print() {
        cout <<name<<" "<<bil<<" "<<cc<< " "\n;
    }

};
class heap
{
void swap_(bill& a, bill& b) {
    
        swap(a.bil,b.bil);
    }
    void heapifyUp(int i)
{
    if(i==1) return ;
    if(arr[i].bil>arr[i/2].bil)
    {
        swap(arr[i],arr[i/2])
        heapifyup(i/2);
    }
}
 public:
 bill arr[100];
 int i=1;
 heap()
 {

 }
 void addbill(string name,int bil,int tt){
 arr[i]=bill(name,bil,tt);
 i++;
 heapifyup(i);

}

void printHp() {
        for (int j = 1; j < i; j++) {
            arr[j].print();
        }
    }
};

int main()
{ 
    heap hp;
  string s;
  int m;
  int cnt=0;
  while(true)
  {
    cin>>s>>m;
    if(s=="q") {break;}
    cnt++;
    hp.addbill(s,m,cnt);
  }
//   for(int j=1;j<hp.i;j++)
//   {
//     cout<<hp.arr[].bill<<" ";
//   }
  hp.printHp();
}















/*
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

// Bill class representing a customer's bill
class Bill {
public:
    char name[50];   // Customer's name
    int amount;      // Bill amount
    int timestamp;   // Timestamp to handle tie-breaking

    // Default constructor
    Bill() {
        strcpy(this->name, "");
        this->amount = 0;
        this->timestamp = 0;
    }

    // Parameterized constructor
    Bill(char name[50], int amount = 0, int timestamp = 0) {
        strcpy(this->name, name);
        this->amount = amount;
        this->timestamp = timestamp;
    }
};

// Priority Queue class
class PriorityQueue {
private:
    Bill heap[MAX_SIZE]; // Array for the max-heap
    int size_;           // Current number of elements in the heap

    // Utility function to swap two bills
    void swap_(Bill& a, Bill& b) {
        Bill temp = a;
        a = b;
        b = temp;
    }

    // Heapify up to maintain max-heap property
    void heapifyUp(int index) {
        while (index > 1) {
            int parent = index / 2;

            // Check if current node is greater than parent
            if (heap[index].amount > heap[parent].amount ||
                (heap[index].amount == heap[parent].amount &&
                 heap[index].timestamp < heap[parent].timestamp)) {
                swap_(heap[index], heap[parent]);
                index = parent; // Move up the tree
            } else {
                break;
            }
        }
    }

    // Heapify down to maintain max-heap property
    void heapifyDown(int index) {
        while (index * 2 <= size_) {
            int left = index * 2;
            int right = index * 2 + 1;
            int largest = index;

            // Compare left child
            if (left <= size_ &&
                (heap[left].amount > heap[largest].amount ||
                 (heap[left].amount == heap[largest].amount &&
                  heap[left].timestamp < heap[largest].timestamp))) {
                largest = left;
            }

            // Compare right child
            if (right <= size_ &&
                (heap[right].amount > heap[largest].amount ||
                 (heap[right].amount == heap[largest].amount &&
                  heap[right].timestamp < heap[largest].timestamp))) {
                largest = right;
            }

            // If the largest is not the current node, swap and continue
            if (largest != index) {
                swap_(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Constructor
    PriorityQueue() {
        size_ = 0;
    }

    // Add a bill to the priority queue
    void addBill(char name[50], int amount, int timestamp) {
        if (size_ >= MAX_SIZE - 1) {
            cout << "Priority queue is full. Cannot add more bills.\n";
            return;
        }

        size_++;
        heap[size_] = Bill(name, amount, timestamp);
        heapifyUp(size_);
    }

    // Process the highest-priority bill
    void processBill() {
        if (size_ == 0) {
            cout << "No bills to process.\n";
            return;
        }

        // Process the root bill
        cout << "Processing bill - Name: " << heap[1].name
             << ", Amount: " << heap[1].amount
             << ", Timestamp: " << heap[1].timestamp << endl;

        // Replace root with the last element and reduce heap size
        heap[1] = heap[size_];
        size_--;

        // Restore the heap property
        heapifyDown(1);
    }

    // Peek the highest-priority bill
    void peekBill() {
        if (size_ == 0) {
            cout << "No bills to peek.\n";
            return;
        }

        cout << "Highest-priority bill - Name: " << heap[1].name
             << ", Amount: " << heap[1].amount
             << ", Timestamp: " << heap[1].timestamp << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Simulate timestamps
    int timestamp = 0;

    // Add bills
    pq.addBill("Alice", 200, timestamp++);
    pq.addBill("Bob", 100, timestamp++);
    pq.addBill("Charlie", 300, timestamp++);
    pq.addBill("Dave", 200, timestamp++);

    // Peek the highest-priority bill
    pq.peekBill();

    // Process bills
    pq.processBill();
    pq.processBill();
    pq.processBill();
    pq.processBill();

    // Try to process an empty queue
    pq.processBill();

    return 0;
}


*/