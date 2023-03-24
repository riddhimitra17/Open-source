#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int ceiling(int a[], int low, int high, int x)
{
    if (x==0){
        return -1;
    }
    int mid;

    while(low<=high)
    {
        mid = low +(high-low)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        else if(x<a[mid])
        {
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    
    int a[]= {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(a)/sizeof(a[0]);
    int x=8;
    int index = ceiling(a, 0, n-1, x);
    if (index == -1)
    {
        cout<<"ceil doesn't exist in array"<<x;
    }
    else{
        cout<<"Ceil is "<<x,a[index];
    }
    return 0;
}
