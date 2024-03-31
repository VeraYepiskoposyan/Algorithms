#include <stdio.h>
#include <stdlib.h>

struct SetElement {
    int data;
    int rank;
    struct SetElement* parent;
};

struct SetElement* makeSet(int data) {
    struct SetElement* newSet = (struct SetElement*)malloc(sizeof(struct SetElement));
    if (newSet) {
        newSet->data = data;
        newSet->rank = 0;
        newSet->parent = newSet;
    }
  
    return newSet;
}

struct SetElement* findSet(struct SetElement* element) {
    if (element != element->parent)
        element->parent = findSet(element->parent); 
    return element->parent;
}


void unionSets(struct SetElement* x, struct SetElement* y) {
    struct SetElement* xRoot = findSet(x);
    struct SetElement* yRoot = findSet(y);

    if (xRoot->rank > yRoot->rank)
        yRoot->parent = xRoot;
    else if (xRoot->rank < yRoot->rank)
        xRoot->parent = yRoot;
    else {
        yRoot->parent = xRoot;
        xRoot->rank++;
    }
}

int testDisjointSet() {
    struct SetElement* sets[10];
    printf("\ntestDisjointSet...\n");

    for (int i = 0; i < 10; i++) {
        sets[i] = makeSet(i);
    }

    unionSets(sets[0], sets[1]);
    unionSets(sets[2], sets[3]);
    unionSets(sets[0], sets[3]);

    printf("Are elements 0 and 1 in the same set? %s\n", findSet(sets[0]) == findSet(sets[1]) ? "Yes" : "No");
    printf("Are elements 0 and 2 in the same set? %s\n", findSet(sets[0]) == findSet(sets[2]) ? "Yes" : "No");

    return 0;
}
