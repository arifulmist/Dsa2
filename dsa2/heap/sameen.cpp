#include <bits/stdc++.h>
using namespace std;

class custom
{
public:
    string name;
    int amount;
    int timestamp;

    custom()
    {
        this->name = "";
        this->amount = 0;
        this->timestamp = 0;
    }

    custom(string name, int amount = 0, int timestamp = 0)
    {
        this->name = name;
        this->amount = amount;
        this->timestamp = timestamp;
    }
};

class Heap
{
    vector<custom> arr;
    void percolate_up(int idx);
    void percolate_down(int idx);

public:
    void Push(custom c);
    custom Pop();
    custom Top();
    bool update(custom c);
    bool empty() { return arr.size() == 0; }
    void delete_at(int idx);
    int find();
};

void Heap::percolate_up(int idx)
{
    while (idx > 0)
    {
        int parent = (idx - 1) / 2;
        if ((arr[parent].amount < arr[idx].amount) ||
            ((arr[parent].amount == arr[idx].amount) && (arr[parent].timestamp > arr[idx].timestamp)))
        {
            swap(arr[parent], arr[idx]);
            idx = parent;
        }
        else
        {
            break;
        }
    }
}

void Heap::percolate_down(int idx)
{
    while (idx < arr.size())
    {
        int left = 2 * idx + 1, right = 2 * idx + 2;
        int largest = idx;

        if (left < arr.size())
        {
            if ((arr[left].amount > arr[largest].amount) ||
                (arr[left].amount == arr[largest].amount && arr[left].timestamp < arr[largest].timestamp))
            {
                largest = left;
            }
        }

        if (right < arr.size())
        {
            if ((arr[right].amount > arr[largest].amount) ||
                (arr[right].amount == arr[largest].amount && arr[right].timestamp < arr[largest].timestamp))
            {
                largest = right;
            }
        }

        if (largest != idx)
        {
            swap(arr[largest], arr[idx]);
            idx = largest;
        }
        else
        {
            break;
        }
    }
}

void Heap::Push(custom c)
{
    arr.push_back(c);
    percolate_up(arr.size() - 1);
}

custom Heap::Pop()
{
    custom c = arr[0];
    swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    percolate_down(0);
    return c;
}

custom Heap::Top()
{
    return arr[0];
}

bool Heap::update(custom c)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].name == c.name)
        {
            arr[i].amount = c.amount;
            percolate_up(i);
            percolate_down(i);
            return true;
        }
    }
    return false;
}

void Heap::delete_at(int idx)
{
    if (idx == 0)
    {
        Pop();
        return;
    }
    swap(arr[idx], arr[arr.size() - 1]);
    arr.pop_back();
    percolate_down(idx);
    percolate_up(idx);
}

int Heap::find()
{
    int minIdx = 0;
    for (int i = (arr.size() + 1) / 2; i < arr.size(); i++)
    {
        if (arr[i].amount < arr[minIdx].amount ||
            (arr[i].amount == arr[minIdx].amount && arr[i].timestamp < arr[minIdx].timestamp))
            minIdx = i;
    }
    cout << "Customer: " << arr[minIdx].name << " Amount: " << arr[minIdx].amount << " Timestamp: " << arr[minIdx].timestamp << endl;
    return minIdx;
}

int main()
{
    string name = "";
    int amount = 0, timestamp = 0;
    Heap h;
    while (name != "Q" || name != "q")
    {
        timestamp++;
        cout << "Customer: " << timestamp << endl;
        cout << "Enter name: ";
        cin >> name;
        if (name == "Q" || name == "q")
            break;
        cout << "Enter amount: ";
        cin >> amount;
        custom c(name, amount, timestamp);
        if (!h.update(c))
            h.Push(c);
    }
    // int idx = h.find();
    //  cout << "minimum: " << idx << endl;

    int count = 0;
    while (!h.empty())
    {
        int mod = (202314129 % 9);
        count++;
        if (count == mod + 1)
        {
            int idx = h.find();
            h.delete_at(idx);
            count = 0;
        }
        custom c = h.Top();
        cout << "Customer: " << c.name << " Amount: " << c.amount << " Timestamp: " << c.timestamp << endl;
        h.Pop();
    }
    return 0;
}

//