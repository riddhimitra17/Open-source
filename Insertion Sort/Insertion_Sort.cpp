#include <iostream>
using namespace std;

void insertionSort(int arr[])
{

    int key;
    for(int i=1; i<5; i++)
    {
        
        key = arr[i]; //picking the element
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1] = key;

    }
}

int main()
{
    int c;
    cout<<"Enter the size of the array"<<endl;
    cin>>c;
    int myarr[c];
    
    cout<<"Enter the elements in the array in random order"<<endl;
    for(int i=0; i<c; i++)
    {
        cin>>myarr[i];
    }
    cout<<"unsorted array"<<endl;
    
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }
    cout<<endl;
    insertionSort(myarr); //sorting actually happens
    cout<<"sorted array"<<endl;
    
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }


    return 0;

}
