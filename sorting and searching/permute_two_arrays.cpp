#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int b[], int k, int n)
{
    sort(a, a+n);
    sort(a, a+n, greater<int>());
    for(int i=0; i<n; i++)
    {
        if(a[i] + b[i] >= k)
        {
            
            cout<<"Yes"<<endl;
            return true;
        }
        else{
            
            cout<<"No"<<endl;
            return false;
        }
    }


}
int main()
{
    
    int a[] = {1, 2, 2, 1};
    int b[] = {3, 3, 3, 4};
    int k=10;
    int n = sizeof(a)/sizeof(a[0]);
    isPossible(a, b, k, n);

}
