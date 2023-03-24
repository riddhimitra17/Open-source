#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void shellsort(int a[], int n)
{
    for (int gap = n/2; gap>0; gap/=2)
    {
        for (int j= gap; j<n;j+=1)
        {
            int temp=a[j];
            int i =0;
            for (i=j; (i>=gap) && (a[i-gap]>temp); i-=gap)
            {
                a[i]=a[i-gap];
            }
            a[i]=temp;
        }
    }
}



int main()
{
    int c;
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
    
    cout<<"\nThe elemets using radix sort are"<<endl;
    shellsort(myarr, c);
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }

}