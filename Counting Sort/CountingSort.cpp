#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void countSort(int arr[], int s, int r)
{
    int outarr[s];
    int countarr[r];
    for (int i =0; i< r; i++)
    {
        countarr[i]=0;
    }
    for (int i =0; i< s; i++)
    {
        ++countarr[arr[i]];
    }
    for (int i =1; i< r; i++)
    {
        countarr[i]=countarr[i]+countarr[i-1];
    }
    for (int i =0; i< s; i++)
    {
        outarr[--countarr[arr[i]]]=arr[i];
    }
    for (int i =0; i< s; i++)
    {
        arr[i]=outarr[i];
    }
}

int main()
{
    int c;
    int range = 10;
    cout<< "enter size of array"<<endl;
    cin>>c;
    int myarr[c];
    cout<<"enter the array elements"<<endl;
    for (int i = 0; i<c; i++)
    {
        cin>>myarr[i];
    }
    cout<<"The elements of the array are:"<<endl;
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }
    
    cout<<"\nThe elemets using counting sort are"<<endl;
    countSort(myarr, c, 10);
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }

}