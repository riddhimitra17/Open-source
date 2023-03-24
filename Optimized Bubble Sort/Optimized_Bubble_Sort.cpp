#include <iostream>
using namespace std;

void optimizedbubbleSort(int arr[])
{
    int rounds=0;

    for(int i=0; i<5; i++)
    {
        rounds++;
        int flag = false;
        for(int j=0; j<5-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag = true;
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        
        }
        if (flag == false) 
        {
            break;
        }

    }
    cout<<"Rounds required = "<<rounds;
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
    optimizedbubbleSort(myarr); //sorting actually happens
    cout<<"\n sorted array"<<endl;
    
    for(int i=0; i<c; i++)
    {
        cout<<myarr[i]<<" ";
    }


    return 0;

}
