#include <iostream>
using namespace std;

void linearSearch(int a[], int n)
{
    int temp = -1;

    for(int i=0; i<5; i++)
    {
        if(a[i]==n)
        {
            cout<<"Element found at: "<<i+1<<"number position"<<endl;
            temp = 0;
        }
        
    }
    if (temp == -1)
    {
        cout<<"Element not found"<<endl;
    }


}

int main()
{
    int c;
    cout<<"Enter the size of the array"<<endl;
    cin>>c;
    int arr[c];
    
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0; i<c; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number you want to search"<<endl;
    
    int num;
    cin>>num;
    linearSearch(arr, num);

    return 0;

}
