#include <stdlib.h>
#include <stdio.h>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShakerSort.h"
#include "ShellSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include "BucketSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

typedef int (*algo_func_t) (int*, int);

typedef struct algoType_s
{
    char* algoName;
    algo_func_t func;
}algoTypes_t;

algoTypes_t algoFuncArr[] =
{
    {
        "selectionSort",
        selectionSort
    },
    {
        "insertionSort",
        insertionSort
    },
};

int main()
{
    int arrtest1[7] = { 1, 9, 6, 4, 3, 2, 10 };
    int arrtest2[8] = { 1, 9, 6, 4, 3, 2, 10, 8 };
    int tmpArr[8];
    for (size_t i = 0; i < sizeof(algoFuncArr) / sizeof(algoTypes_t); i++)
    {
        int n = sizeof(arrtest1) / sizeof(arrtest1[0]);
        memcpy(tmpArr, arrtest1, sizeof(arrtest1));
        algoFuncArr[i].func(tmpArr, n);
        printf("\nRunning %s for array1...\n", algoFuncArr[i].algoName);
        for (int i = 0; i < n; i++) {
            printf("%d ", tmpArr[i]);
        }

        n = sizeof(arrtest2) / sizeof(arrtest2[0]);
        memcpy(tmpArr, arrtest2, sizeof(arrtest2));
        algoFuncArr[i].func(tmpArr, n);
        printf("\nRunning %s for array2...\n", algoFuncArr[i].algoName);
        for (int i = 0; i < n; i++) {
            printf("%d ", tmpArr[i]);
        }

    }
 //   float arr3[6] = { 0.67f, 0.98f, 0.45f, 0.27f, 0.65f, 0.01f };
 //   selectionSort(arr, 7); 
 //   insertionSort(arr, 7);
 //   bubbleSort(arr, 7);
 //   shakerSort(arr1, 8);
 //   shellSort(arr, 7);
 //   countingSort(arr1, 8);
 //   radixSort(arr, 7);
 //   bucketSort(arr3, 6);
 //   mergeSort(arr1, 7);
 //   quickSort(arr1, 7);
 //   heapSort(arr, 7);

}


