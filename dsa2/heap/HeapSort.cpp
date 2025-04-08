#include<bits/stdc++.h>
using namespace std;

void HeapifyDown(int arr[], int index, int n)
    {
        int largest = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            HeapifyDown(arr,largest, n);
        }
    }

void heapSort(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        HeapifyDown(arr,i,n);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(arr[i],arr[0]);
        HeapifyDown(arr,0,i);
    }
}

int main()
{
    int arr[6] = {4,6,8,1,3,9};

    heapSort(arr,6);

    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
}

