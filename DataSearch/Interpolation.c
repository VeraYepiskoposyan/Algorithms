#include <stdio.h>


int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x)
                return low;
            return -1;
        }

        
        int pos = low + (int)(((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

        
        if (arr[pos] == x)
            return pos;

        
        if (arr[pos] > x)
            high = pos - 1;
        
        else
            low = pos + 1;
    }
    return -1; 
}


int testInterpolationSearch() {
    int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 50;
    int index = interpolationSearch(arr, n, x);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    return 0;
}