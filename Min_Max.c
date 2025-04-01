#include<stdio.h>
void maxmin(int a[],int l,int r,int* max,int* min)
{
    if(l==r)
    {
        *max=a[l];
        *min=a[r];
        return;
    }
    else if(r==l+1)
    {
        if(a[l]>a[r])
        {

            *max=a[l];
            *min=a[r];
        }
        else
        {
            *max=a[r];
            *min=a[l];
        }
        return;
    }
    else
    {
        int mid=(l+r)/2;
        int max1,min1,max2,min2;
        maxmin(a,l,mid,&max1,&min1);
        maxmin(a,mid+1,r,&max2,&min2);
        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}
int main() {
    int n;

    // Taking dynamic input for array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];  // Declare an array of size n

    // Taking dynamic input for array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;

    // Find the min and max values
    maxmin(arr, 0, n - 1, &max, &min);

    // Output the results
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}