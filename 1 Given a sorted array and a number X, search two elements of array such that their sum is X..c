#include<stdio.h>
void Pair(int a[], int n, int x)
{
    int res_l, res_r;  
    
    int l = 0, r = n-1;
 
    while (r > l)
    {
        
       if (a[l] + a[r] == x)
       {
           res_l = l;
           res_r = r;

       }
       
       if (a[l] + a[r] >= x){
            r--;
       }
       else if (a[l] + a[r] < x){
           l++;
       }
    }
    printf("The set of the value are %d and %d \n", a[res_l], a[res_r]);
}
int main(){
    int sum;
    int a[]={10,30,50,60};
    
    
    printf("Enter the sum: ");
    scanf("%d", &sum);
    
    int size = sizeof(a)/sizeof(a[0]);
    Pair(a, size, sum);
}