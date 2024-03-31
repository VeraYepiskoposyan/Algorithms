#include <stdlib.h>
#include <memory.h>

int countingSort(int* arr, int n) {
    int range;
    int min = 0;
    int max = 0;
    int ret = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    range = max - min + 1;
    int* freqArr = (int*)malloc(range * sizeof(int));
    if (freqArr) {
        int* countArr = (int*)malloc(range * sizeof(int));
        if (countArr) {
            int* sortedArr = (int*)malloc(n * sizeof(int));
            if (sortedArr) {
                memset(freqArr, 0, range * sizeof(int));

                for (int i = 0; i < n; i++) {
                    freqArr[arr[i]]++;
                }
                countArr[0] = freqArr[0];
                for (int i = 1; i < range; i++) {
                    countArr[i] = countArr[i - 1] + freqArr[i];
                }
                for (int i = n - 1; i >= 0; i--) {
                    int elIndex = countArr[arr[i]] - 1;
                    sortedArr[elIndex] = arr[i];
                    countArr[arr[i]]--;
                }
                memcpy(arr, sortedArr, n * sizeof(int));
                free(sortedArr);
                ret = 0;
            }

            free(countArr);
        }

        free(freqArr);
    }
    return ret;
}
