#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

struct bucketNode {
    struct bucketNode* next;
    float data;
}; 

static insertBucketDataBySort(struct bucketNode** pList, float data) {
    struct bucketNode* node = malloc(sizeof(struct bucketNode));
    if (node) {
        node->data = data;
        node->next = NULL;
        if (*pList == NULL) {
            *pList = node;
        }
        else {
            struct bucketNode* temp = *pList;
            struct bucketNode* current = temp;
            while (temp != NULL && temp->data < node->data) {
                current = temp;
                temp = temp->next;
            }
            current->next = node;
            node->next = temp;
        }
    }

}

int bucketSort(float* arr, int n) {
    int ret = -1;
    struct bucketNode** buckets = malloc(n * sizeof(struct bucketNode*));
    memset(buckets, 0, n * sizeof(struct bucketNode*));
    if (buckets) {
        for (int i = 0; i < n; i++) {
            int index = (int)(n * arr[i]);
            insertBucketDataBySort(&buckets[index], arr[i]);
        }
        int i = 0;
        for (int j = 0; j < n; j++) {
            struct bucketNode* temp = buckets[j];
            struct bucketNode* node;
            while (temp != NULL) {
                arr[i] = temp->data;
                i++;
                node = temp;
                temp = temp->next;
                free(node);
            }
        }
        free(buckets);
        ret = 0;
    }

    return ret;
}