#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    
            int i=l;
            int j = m+1;
            int k = l;
            int temp[10];
            while(i<=m && j<=r)
            {
                if(arr[i]<=arr[j])
                {
                    temp[k] = arr[i];
                    i++;
                    k++;
                }
                else
                {
                    temp[k] = arr[j];
                    j++;
                    k++;
                }
            } 
            while(i<=m)
            {
                    temp[k] = arr[i];
                    i++;
                    k++;
            }
            while(j<=r)
            {
                    temp[k] = arr[j];
                    j++;
                    k++;
            }
            for(int p =l;p<=r;p++)
            {
                arr[p]=temp[p];
            }


}
void mergeSort(int arr[], int l, int r)
{
    if (l<r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int c;    
    cout<<" Enter the size of the array"<<endl;
    cin>>c;
    int myarr[c];

    cout<<"Enter the elements of the array"<<endl;
    for(int i=0; i<c; i++)
    {
        cin>>myarr[i];
    }
    
    cout<<"Unsorted array"<<endl;
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }
    mergeSort(myarr, 0, c);
    cout<<"\n sorted array"<<endl;
    
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }


    return 0;

}