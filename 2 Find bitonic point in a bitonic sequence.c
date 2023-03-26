#include<stdio.h>
int binarySearch(int arr[], int left, int right)
{
	if (left <= right)
	{
		int mid = (left+right)/2;
		if (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
			return mid;
		if (arr[mid] < arr[mid+1])
			return binarySearch(arr, mid+1,right);
		else
			return binarySearch(arr, left, mid-1);
	}

	return -1;
}
int main()
{
	int arr[] = {1, 6, 10, 20, 30, 4, 3, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int index = binarySearch(arr, 1, n-2);
	if (index != -1)
	printf("%d \n",arr[index]);
	return 0;
}