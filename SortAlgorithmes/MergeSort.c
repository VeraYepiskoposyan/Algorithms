#include <stdlib.h>

static void merge(int* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));

    if (L) {
        int* R = (int*)malloc(n2 * sizeof(int));
        if (R) {


            for (i = 0; i < n1; i++)
                L[i] = arr[l + i];
            for (j = 0; j < n2; j++)
                R[j] = arr[m + 1 + j];

            i = 0;
            j = 0;
            k = l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                }
                else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }

            free(R);
        }
        free(L);
    }
}

static void mergeSortRange(int* arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSortRange(arr, l, m);
        mergeSortRange(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int mergeSort(int* arr, int n)
{
    mergeSortRange(arr, 0, n - 1);
    return 0;
}
