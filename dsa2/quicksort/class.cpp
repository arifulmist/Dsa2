#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nl "\n"

int partitionMiddle(vector<int>& a, int s, int e) {
    int mid = s + (e - s) / 2; // Finding the middle index
    int pivot = a[mid];
    swap(a[mid], a[e]); // Move middle element to end (choosing as pivot)
     // Pivot is now at the end
    int i = s - 1; 

    for (int j = s; j < e; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[e]); // Place pivot at correct position
    return i + 1;
}
int partitionleft(vector<int>& A, int p, int r) {
    int pivot = a[s];/// samner ta pivot dhore 
    int i = s + 1;
    for (int j = s + 1; j <= e; j++)
     {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[s], a[i - 1]);
    return i - 1;
}
int Partitionright(vector<int>& A, int p, int r) {
    int x = A[r]; // Pivot element last er ta pivott dhorle

    int i = p - 1;

    for (int j = p; j <r; j++) 
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
 void quicksort(int s,int e,vector<int>& a)
 {
    if(s<e)
    {
        int p=partitionMiddle(a,s,e);
        quicksort(s,p-1,a);
        quicksort(p+1,e,a);
    }
}
int main()
{
    ll n;
    cin>>n;
    vector<int>a(n);
    for(ll i=0;i<n;i++)
    {

        cin>>a[i];
    }
    quicksort(0,n-1,a);
    for(ll i=0;i<n;i+=1)
    {
        cout<<a[i]<<" ";
    }
     
}