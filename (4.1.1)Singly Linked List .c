#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct LinkedList {
    struct Node* head;
    int size;
};
void insert(struct LinkedList* list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    list->size++;
    printf("Element %d inserted at position %d\n", data, position);
}
void deleteNode(struct LinkedList* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Invalid position\n");
        return;
    }
    struct Node* temp = list->head;

    if (position == 0) {
        list->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
    list->size--;
    printf("Element at position %d deleted\n", position);
}
void display(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void reverse(struct LinkedList* list) {
    struct Node *prev = NULL, *curr = list->head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct Node* temp = prev;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    curr = prev;
    prev = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}
int main() {
    struct LinkedList list;
    list.head = NULL;
    list.size = 0;

    int n,c;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    if (n > 0) {
        printf("Enter the elements:\n");
    }
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(&list, x, list.size);
    }
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Reverse\n4. Display\n5. Exit\n");
        scanf("%d", &c);
        if (c= 1) {
            int data,pos;
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insert(&list, data, pos);
        } else if (choice == 2) {
            int pos;
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteNode(&list, pos);
        } else if (choice == 3) {
            reverse(&list);
        } else if (choice == 4) {
            display(&list);
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}
