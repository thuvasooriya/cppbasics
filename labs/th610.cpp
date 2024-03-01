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
    root = new node;
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

// #include <iostream>
//
// using namespace std;
//
// class Node {
// public:
//   int data;
//   Node *left;
//   Node *right;
//   Node(int d) {
//     data = d;
//     left = NULL;
//     right = NULL;
//   }
// };
//
// class Solution {
// public:
//   void preOrder(Node *root) {
//
//     if (root == NULL)
//       return;
//
//     std::cout << root->data << " ";
//
//     preOrder(root->left);
//     preOrder(root->right);
//   }
//
//   Node *insert(Node *root, int data) {
//     Node *n = new Node(data); // make a node with current data
//     std::cout << "node created" << std::endl;
//     if (root == NULL) {
//       root = n;
//       std::cout << "node assigned to root" << std::endl;
//       return root;
//     }
//     Node *tmp = root; // take a copy of current root
//     std::cout << "tmp node created" << std::endl;
//     while (true) {
//       if (tmp->data > n->data) {
//         tmp = tmp->left ? tmp->left : (tmp->left = n);
//         if (!tmp->left)
//           break;
//       } else {
//         tmp = tmp->right ? tmp->right : (tmp->right = n);
//         if (!tmp->right)
//           break;
//       }
//     }
//     return root;
//   }
// };
//
// int main() {
//
//   Solution myTree;
//   Node *root = NULL;
//
//   int t;
//   int data;
//
//   std::cin >> t;
//
//   while (t-- > 0) {
//     std::cin >> data;
//     root = myTree.insert(root, data);
//   }
//
//   myTree.preOrder(root);
//
//   return 0;
// }

/*
You are given a pointer to the root of a binary search tree and values to be
inserted into the tree. Insert the values into their appropriate position in the
binary search tree and return the root of the updated binary tree. You just have
to complete the function.

You are given a function,

Node * insert (Node * root, int data) ‹

Input Format

• First line of the input contains t, the number of nodes in the tree.
• Second line of the input contains the list of t elements to be inserted to the
tree.

Constraints

• No. of nodes in the tree, 1 ≤ t≤ 5000
• Value of each node in the tree, 1 ≤ t] ≤ 10000

Output Format

Return the items in the binary search tree after inserting the values into the
tree. Start with the root and follow each element by its left subtree, and then
its right subtree.

Sample Input
6
423176

Sample Output
421376
Sample Explanation

The binary tree after inserting the 6 elements in the given order will look like
this.
4
/ 1
2 7
/\ /
1 3 6
*/
