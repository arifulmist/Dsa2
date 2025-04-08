#include <bits/stdc++.h>
using namespace std;
class bill {
public:
    string name;
    int amount;
    int time;
    bill() {
        name = " ";
        amount = 0;
        time = 0;
    }

    bill(string name, int amount, int time) {
        this->name = name;
        this->amount = amount;
        this->time = time;
    }
};

class PriorityQueue {
private:
    bill arr[101];
    int size;

    void heapifyup(int ind)
    {
        if (ind == 1) return;
        int parent = ind / 2;
        if (arr[ind].amount > arr[parent].amount || 
           (arr[ind].amount == arr[parent].amount && arr[ind].time < arr[parent].time)) {
            swap(arr[ind], arr[parent]);
            heapifyup(parent);
        }
    }

    void heapifydown(int ind) 
    {
        int high = ind;
        int left = 2 * ind;
        int right = 2 * ind + 1;
        if(left <= size &&(arr[left].amount > arr[high].amount ||(arr[left].amount == arr[high].amount && arr[left].time < arr[high].time)))
         {
            high = left;
        }

        if (right <= size && (arr[right].amount > arr[high].amount ||(arr[right].amount == arr[high].amount && arr[right].time < arr[high].time))) 
        {
            high = right;
        }

        if (high != ind) {
            swap(arr[ind], arr[high]);
            heapifydown(high);
        }
    }

public:
    PriorityQueue(){
        size=0;
    }

    void insert(bill val) {
        size++;
        arr[size] = val;
        heapifyup(size);
    }

    void pop() {
        if (size == 0) return;
        swap(arr[1], arr[size]);
        size--;
        heapifydown(1);
    }

    bill peek() {
        return arr[1];
    }

    bool empty() {
        return size == 0;
    }

    bool update(bill &x) {
        for (int i = 1; i <= size; i++) {
            if (x.name == arr[i].name) {
                arr[i].amount = x.amount;
                arr[i].time = x.time;
                heapifyup(i);
                heapifydown(i);
                return true;
            }
        }
        return false;
    }

    void delete_at(int ind) {
        if (ind < 1 || ind > size) return;
        swap(arr[ind], arr[size]);
        size--;
        heapifydown(ind);
        heapifyup(ind);
    }

    int findmin()
    {
        int mn = INT_MAX;
        int index = -1;
        for(int i = size / 2 + 1; i <= size; i++)
        { 
            if (arr[i].amount <mn||(arr[i].amount == mn && arr[i].time < arr[index].time))
             {
                mn = arr[i].amount;
                index = i;
            }
        }
        return index;
    }

    void processbill()
    {
        int mod = 202314110%9; 
        int cc = 0;
        while (!empty()) {
            if (size == 0) {
            cout << "No bills to process." << endl;
            return;
        }
            bill mnn;
            if (cc == mod+1) {
                cc = 0;
                int minIndex = findmin();
                mnn = arr[minIndex];
                delete_at(minIndex);
            } else {
                cc++;
                mnn = peek();
                pop();
            }
            cout << mnn.name << " " << mnn.amount << " " << mnn.time << "\n";
        }
    }
};

int main() {
    PriorityQueue pp;
    string name;
    int amount;
    int tt = 0;

    while (true) {
        cout << "Enter Customer " << ++tt << ":\n";
        cout << "Name: ";
        cin >> name;
        if (name == "Q" || name == "q") break;
        cout << "Amount: ";
        cin >> amount;
        bill b(name, amount, tt);
        if (!pp.update(b)) pp.insert(b);
    }

    pp.processbill();
    pp.processbill();
    return 0;
}
