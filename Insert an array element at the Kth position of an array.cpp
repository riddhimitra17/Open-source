#include<stdio.h>

void printArr(int arr[], int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int size,k,val;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    size++;
    printf("Enter the array:\n");
    int arr[size];
    for(int i=0;i<size-1;i++)
        scanf("%d",&arr[i]);
    printf("Enter the value of k: ");
    scanf("%d",&k);
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    for(int i=size-1;i>=k-1;i--)
        arr[i]=arr[i-1];
    arr[k-1]=val;

    printf("The new array after insertion is: ");
    printArr(arr,size);

    return 0;
}
