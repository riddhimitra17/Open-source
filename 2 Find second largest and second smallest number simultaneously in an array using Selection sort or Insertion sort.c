#include <stdio.h>
    void main ()
    {
 
        int num[30];
        int i, j, a, n, count, avg;
 
        printf("Enter the size of array\n");
        scanf("%d", &n);
 
        printf("Enter the numbers \n");
        for (i = 0; i < n; ++i)
            scanf("%d", &num[i]);
 
        for (i = 0; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (num[i] < num[j])
                {
                    a = num[i];
                    num[i] = num[j];
                    num[j] = a;
                }
            }
 
        }
 
 
        for (i = 0; i < n; ++i)
        {
           
        }
 
        printf("The 2nd largest number is  = %d\n", num[1]);
        printf("The 2nd smallest number is = %d\n", num[n - 2]);

    }