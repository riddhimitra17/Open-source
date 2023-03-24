#include <iostream>
using namespace std;

void selectionSort(int arr[])
{

    
    for(int i=0; i<4; i++)
    {
        
        int min = i;
        for(int j=i+1; j<5; j++)
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
    selectionSort(myarr); //sorting actually happens
    cout<<"sorted array"<<endl;
    
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }


    return 0;

}
