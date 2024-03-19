// pure C implementaion of 61
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void preOrder(struct node *root) {
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

struct node *insert(struct node *root, int data) {

  if (root == NULL) {
    // todo: fix there is an error here
    // root is not initialized properly
    struct node *n;
    root = n;
    root->data = data;
    root->left = NULL;
    root->right = NULL;

  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

int main() {

  struct node *root = NULL;

  int t;
  int data;

  scanf("%d", &t);

  while (t-- > 0) {
    scanf("%d", &data);
    root = insert(root, data);
  }

  preOrder(root);
  return 0;
}
