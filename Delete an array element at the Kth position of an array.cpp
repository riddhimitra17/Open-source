#include<stdio.h>

void printArr(int arr[], int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int size,k;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter the array:\n");
    int arr[size];
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("Enter the value of k: ");
    scanf("%d",&k);
    for(int i=k-1;i<size;i++)
        arr[i]=arr[i+1];
    
    printf("The new array: ");
    printArr(arr,size-1);

    return 0;
}
