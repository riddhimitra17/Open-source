#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int partitionindex( int arr[], int s, int e)
{
    int pivot = arr[e];
    int pindex = s;
    for (int i = s; i<e; i++)
    {
        if (arr[i]<=pivot)
        {
            int temp = arr[i];
            arr[i]=arr[pindex];
            arr[pindex] = temp;
            pindex++;

        }
    }
    int temp1 = arr[e];
    arr[e] = arr[pindex];
    arr[pindex]=temp1;
    return pindex;
}

int quicksort(int arr[], int st, int en)
{
    if (st<en)
    {
        int p = partitionindex(arr,st,en);
        int first = quicksort(arr, st, p-1);
        int second = quicksort(arr, p+1, en);
        return first;
        return second;
    }
    
}

int main()
{
    int c;
    cout<<"Enter the size of the array"<<endl;
    cin>>c;
    int a[c];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<c; i++)
    {
        cin>>a[i];
    }
    cout<<"Array elements are:"<<endl;
    for(int i = 0; i<c; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nThe elements in sorted order is"<<endl;
    quicksort(a,0,(c-1));
    for(int i = 0; i<c; i++)
    {
        cout<<a[i]<<" ";
    }

}