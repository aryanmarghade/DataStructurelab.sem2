#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return create(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void range(struct Node* root, int l ,int h) {
    if (root == NULL) return;
    if (root->data > l)
        range(root->left, l, h);
    if (root->data >= l && root->data <= h)
        printf("%d ", root->data);
    if (root->data < h)
        range(root->right, l, h);
}

int main() {
    printf(" NAME: Aryan Marghade \n PRN: 25070521215 \n SECTION: D(D2) \n SUBJECT: Data  Structures Lab \n");
    struct Node* root = NULL;
    int n, x, l, h;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d %d", &l, &h);
    range(root, l, h);
    return 0;
}
