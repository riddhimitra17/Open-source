#include<stdlib.h>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long* puzzle(int a[], int n)
{
    
    int prod = 1;
    int flag= 0;

    for(int i=0; i<n; i++)
    {
        if (a[i]==0)
        {flag++;}
        else
        {prod *= a[i];}
        
    }
    long* arr = new long[n];

    for (int i=0; i<n; i++)
    { 
        //if no of elements in arr with value 0 is more than 1, then each value in new arr will be = 0
        if (flag>1)
        {
            arr[i]=0;
        }
        //if no element having val 0, then we insert product/a[i] in the new arr
        else if(flag == 0)
        {
            arr[i]= (prod/a[i]);
        }
        //if one element having value 0, then all the elements except that index value will be = 0
        else if(flag == 1 && a[i] != 0)
        {
            arr[i]=0;
        }
        //if (flag ==1 && a[i] == 0)
        else{
            arr[i]= prod;
        }
    }
    return arr;

}
int main()
{
    int c;
    cout<<"Enter the size of the array"<<endl;
    cin>>c;
    int array[c];
    
    cout <<"Enter the array elements"<<endl;
    for(int i=0;i<c;i++)
    {
        cin>>array[i];
    }
    cout<<"the array is"<<endl;
    for(int i=0; i<c; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    long* ans;
    ans = puzzle(array,c);
    for(int i = 0; i<c; i++)
    {
        cout << ans[i] << " ";
    }    
    return 0;

}
