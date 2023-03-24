#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


int getMax(int arr[], int size)
{
    int max = arr[0];
    for(int i = 1; i<size; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
        
        
    }
    return max;
}

void countSort(int arr[], int size, int div)
{

    int outarr[size];
    int countarr[10]={0};

    for (int i =0; i< size; i++)
    {
        countarr[(arr[i]/div)%10]++;
    }
    for (int i =1; i< 10; i++)
    {
        countarr[i]+=countarr[i-1];
    }
    for (int i = size-1; i>=0 ; i--)
    {
        outarr[countarr[(arr[i]/div)%10]-1]=arr[i];
        countarr[(arr[i]/div)%10]--;
    }
    for (int i =0; i< size; i++)
    {
        arr[i]=outarr[i];
    }
}

 void radixSort(int arr[], int size)
 {
    int m = getMax(arr, size);
    for (int div = 1; m/div>0; div*= 10)
    {
        countSort(arr, size, div);
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
    radixSort(myarr, c);
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }

}