#include<stdio.h>
void doMerge(int arr1[],int arr2[], int arr3[], int size1, int size2);
void printArr(int arr[], int size);

int main()
{
    int size1,size2;

    printf("Enter the size of the array: ");
    scanf("%d",&size1);
    printf("Enter the array:\n");
    int arr1[size1];
    for(int i=0;i<size1;i++)
        scanf("%d",&arr1[i]);

    printf("Enter the size of the other array: ");
    scanf("%d",&size2);
    printf("Enter the array:\n");
    int arr2[size2];
    for(int i=0;i<size2;i++)
        scanf("%d",&arr2[i]);
    
    int arr3[size1+size2];
    doMerge(arr1,arr2,arr3,size1,size2);

    printf("The first array is: ");
    printArr(arr1,size1);
    printf("The second array is: ");
    printArr(arr2,size2);
    printf("The third merged array is: ");
    printArr(arr3,size1+size2);

    return 0;
}

void doMerge(int arr1[],int arr2[], int arr3[], int size1, int size2)
{
    int i,j,k;
    i=j=k=0;
 
    while (i<size1 && j<size2)
    {
        if (arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];
        else
            arr3[k++]=arr2[j++];
    }
    while (i<size1)
        arr3[k++]=arr1[i++];
 
    while (j<size2)
        arr3[k++]=arr2[j++];
}

void printArr(int arr[], int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
