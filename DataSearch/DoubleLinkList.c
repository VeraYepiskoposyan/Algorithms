#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        newNode->next = *headRef;
        (*headRef)->prev = newNode;
        *headRef = newNode;
    }
}

void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    }
    else {
        struct Node* temp = *headRef;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

static void deleteNode(struct Node** headRef, int data) {
    if (*headRef == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *headRef;
    struct Node* prevNode = NULL;

    if (temp != NULL && temp->data == data) {
        *headRef = temp->next;
        if (*headRef != NULL)
            (*headRef)->prev = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prevNode = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    prevNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = prevNode;
    free(temp);
}

static struct Node* search(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; 
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int testDoubleLinkList() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    printf("Original list: ");
    printList(head);

    int searchData = 20;
    struct Node* searchResult = search(head, searchData);
    if (searchResult != NULL) {
        printf("Node with data %d found.\n", searchData);
    }
    else {
        printf("Node with data %d not found.\n", searchData);
    }

    int deleteData = 20;
    deleteNode(&head, deleteData);
    printf("List after deleting node with data %d: ", deleteData);
    printList(head);

    return 0;
}
