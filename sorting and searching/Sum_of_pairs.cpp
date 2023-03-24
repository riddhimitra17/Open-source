#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sum(long long arr[], long long brr[], int n, long long k)
{
    long long a = *max_element(arr, arr+n);
    long long b = *max_element(brr, brr+n);
    long long ans = a+b;
    
    
    
    return ans>=k;
}
int main()
{
    int c;
    cout<<"Enter the size of the array"<<endl;
    cin>>c;
    long long arr[c];
    long long brr[c];
    long long k;
    cout<<"Enter the elements of the first array"<<endl;
    for(int j=0; j<c; j++)
    {
        cin>>arr[j];
    }
    cout<<"Enter the elements of the second array"<<endl;
    for(int i=0; i<c; i++)
    {
        cin>>brr[i];
    }
    cout<<"Enter the sum"<<endl;

    cin>>k;
    int n = sizeof(arr)/sizeof(arr[0]);

    if (sum(arr, brr, n, k)){
        cout<<"yes"<<endl;

    }
    else{
        cout<<"no"<<endl;
    }
    
}
