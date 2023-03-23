#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if (arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]<x)
        {
            left = mid + 1; 
        }
        else
        {
            right = mid - 1;
        }
        
    }
    return -1;
}

int main()
{
    int output;
    int c;
    cout<<"Enter the size of the array"<<endl;
    cin>>c;
    int myarr[c];
    
    cout<<"Enter the elements in the array in sorted order"<<endl;
    for(int i=0; i<c; i++)
    {
        cin>>myarr[i];
    }
    cout<<"Enter the number you want to search"<<endl;
    
    int num;
    cin>>num;
    output = binarySearch(myarr, 0, c, num);
    if(output==-1)
    {
        cout<<"No match found"<<endl;
    }
    else
    {
        cout<<"Match found at: "<<output<<endl;
    }

    return 0;

}
