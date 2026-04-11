#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} *NODE;
NODE createNode(int x) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
NODE addNode(NODE first, int x) {
    NODE temp = createNode(x);
    if (first == NULL)
        return temp;
    NODE cur = first;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return first;
}
NODE concatenate(NODE t1, NODE t2) {
    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;

    NODE cur = t1;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = t2;
    return t1;
}
void displayList(NODE first) {
    NODE temp = first;
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    NODE sll1 = NULL, sll2 = NULL;
    int choice;
    while (1) {
        printf("\n1. Create SLL1\n2. Create SLL2\n3. Display SLL1\n4. Display SLL2\n5. Concatenation\n6. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int x;
            sll1 = NULL;
            printf("Enter elements for SLL1 (-1 to end):\n");
            while (1) {
                scanf("%d", &x);
                if (x == -1)
                    break;
                sll1 = addNode(sll1, x);
            }
        } else if (choice == 2) {
            int x;
            sll2 = NULL;
            printf("Enter elements for SLL2 (-1 to end):\n");
            while (1) {
                scanf("%d", &x);
                if (x == -1)
                    break;
                sll2 = addNode(sll2, x);
            }
        } else if (choice == 3) {
            displayList(sll1);
        } else if (choice == 4) {
            displayList(sll2);
        } else if (choice == 5) {
            sll1 = concatenate(sll1, sll2);
        } else if (choice == 6) {
            break;
        }
    }

    return 0;
}
