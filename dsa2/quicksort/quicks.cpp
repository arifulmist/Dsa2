#include<bits/stdc++.h>
using namespace std;
#define ll int
#define pi pair<ll,ll>
#define nl "\n"

// Function to partition the array
int Partition(vector<int>& A, int p, int r) {
    int x = A[r]; // Pivot element
    int i = p - 1;
 
    for (int j = p; j <= r - 1; j++) 
    {
        if (A[j] <= x) 
        {
            i++;
            swap(A[i], A[j]); // Exchange A[i] and A[j]
        }
    }
    swap(A[i + 1], A[r]); // Exchange A[i + 1] and A[r]
    return i + 1;
}

// QuickSort function
void QuickSort(vector<int>& A, int s, int e) {
    if (s < e) {
        int q = Partition(A, s, e); // Partition the array
        QuickSort(A, s, q - 1);     // Sort the left subarray
        QuickSort(A, q + 1, e);     // Sort the right subarray
    }
}

int main() {
    
    int n ;
    cin>>n;
    vector<ll>A(n);
    for(ll i=0;i<n;i++) cin>>A[i];


    QuickSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);

}

int main() {

    int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}



*/