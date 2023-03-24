#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

void sort(int arr[])
{
    for(int i=0; i<5; i++)
    {
        int min = i;
        for(int j=i+1; j<6; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }

    
    }
}
bool findpair(int a[], int size, int n)
{
    unordered_map<int, int>mpp;
    for (int i=0; i<size; i++)
    {
        mpp[a[i]]++;

        if(n==0 && mpp[a[i]]>1)
        return true;
    }
    if (n==0)
    return false;
    for (int i=0; i<size; i++)
    {
        if (mpp.find(n+a[i]) != mpp.end() )
        {
            cout <<"Pair found ("<<a[i]<<","<< n + a[i] <<")"<< endl;
            return true;
        }
        
                   
    }
    cout<<"Pair not found"<<endl;
    return false;
}
int main()
{
    int a[] = { 8,1,40, 30, 100 };
    sort(a);
    cout<<"Sorted array"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<a[i]<<" "<<endl;
    }
    int size = sizeof(a)/sizeof(a[0]);
    int n = 60;
    findpair(a, size, n);
    return 0; 
}
