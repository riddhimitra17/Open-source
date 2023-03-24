#include <stdlib.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int mincost(int a[], int n)
{
    int y;
    if (n%2 == 1)
    {
        y = a[n/2];
    } 
    else
    {
        y = (a[n/2]+ a[(n-2)/2])/2;
    }
    int s = 0;
    for ( int i =0; i<n; i++)
    {
        s+= abs(a[i]-y);
    }
    return s;

}
int main()
{
    int c;    
    cout<<"Enter the  size of the array"<<endl;
    cin>>c;
    int arr[c];
    cout<<"Enter the array elements"<<endl;
    for (int i = 0; i<c; i++)
    {
        cin>>arr[i];
    }
    cout<<"The elements of the array are"<<endl;
    for (int i=0; i<c; i++)
    {
        cout<<arr[i]<<" ";
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"\nMinimum cost"<<endl<<mincost(arr, n);
    
}
