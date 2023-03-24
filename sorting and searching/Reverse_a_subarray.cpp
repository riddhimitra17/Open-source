#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool sortarr(int a[], int n)
{
    int x=-1;
    int y=-1;

    for (int i=0; i<n-1; i++)
    {
        if (a[i]>a[i+1])
        {
            if (x==-1){
                x=i;
            }
            y=i+1;
        }
    }
    if (x!=-1)
    {
        reverse(a+x, a+y+1);
        for (int i=0; i<n-1; i++)
        {
            if (a[i]>a[i+1])
            {
                return false;
                return 0;
            }
            
        }

    }
    return true;
}
int main()
{
    int c;
    cout<<"Enter the size of the array"<<endl;
    cin>>c;
    int arr[c];
    
    cout <<"Enter the array elements"<<endl;
    for(int i=0;i<c;i++)
    {
        cin>>arr[i];
    }
    cout<<"the array is"<<endl;
    for (int i = 0; i<c; i++)
    {
        cout<<arr[i]<<"";
    }
    cout<<endl;
    int n=sizeof(arr)/sizeof(arr[0]);

    sortarr(arr,n) ? (cout<<"yes"<<endl)
                    : (cout<<"no"<<endl);
    return 0;

}
