#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  Node *insert(Node *root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node *tmp;
      if (data <= root->data) {
        tmp = insert(root->left, data);
        root->left = tmp;
      } else {
        tmp = insert(root->right, data);
        root->right = tmp;
      }

      return root;
    }
  }

  bool has_data(struct Node *tree, int k) {
    if (tree == NULL)
      return false;
    if (tree->data == k)
      return true;
    return has_data(tree->left, k) || has_data(tree->right, k);
  }

  Node *lca(Node *tree, int v1, int v2) {

    if (tree == NULL)
      return NULL;
    if (tree->data > v1 && tree->data > v2)
      return lca(tree->left, v1, v2);
    if (tree->data < v1 && tree->data < v2)
      return lca(tree->right, v1, v2);
    if (tree->data < v1 && tree->data > v2) {
      if (has_data(tree->left, v2) && has_data(tree->right, v1)) {
        return tree;
      } else
        return NULL;
    }
    if (tree->data > v1 && tree->data < v2) {
      if (has_data(tree->left, v1) && has_data(tree->right, v2)) {
        return tree;
      } else
        return NULL;
    }
    if (tree->data == v1) {
      if (tree->data < v2) {
        if (has_data(tree->right, v2))
          return tree;
        else
          return NULL;
      }
      if (tree->data > v2) {
        if (has_data(tree->left, v2))
          return tree;
        else
          return NULL;
      }
      if (tree->data == v2)
        return tree;
    }
    if (tree->data == v2) {
      if (tree->data < v1) {
        if (has_data(tree->right, v1))
          return tree;
        else
          return NULL;
      }
      if (tree->data > v1) {
        if (has_data(tree->left, v1))
          return tree;
        else
          return NULL;
      }
      if (tree->data == v1)
        return tree;
    }

    return NULL;
  }
};

int main() {

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0) {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  int v1, v2;
  std::cin >> v1 >> v2;

  Node *ans = myTree.lca(root, v1, v2);

  std::cout << ans->data;

  return 0;
}

// #include <iostream>
// // #include <queue>
// // #include <vector>
//
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };
//
// Node* newNode(int data) {
//     Node* node = new Node;
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }
//
// Node* lca(Node* root, int v1, int v2) {
//     if (root == NULL)
//         return NULL;
//
//     if (root->data < v1 && root->data < v2)
//         return lca(root->right, v1, v2);
//     else if (root->data > v1 && root->data > v2)
//         return lca(root->left, v1, v2);
//     else
//         return root;
// }
//
// int main() {
//     Node* root = newNode(4);
//     root->left = newNode(2);
//     root->right = newNode(7);
//     root->left->left = newNode(1);
//     root->left->right = newNode(3);
//     root->right->left = newNode(6);
//     root->right->right = newNode(9);
//
//     int v1 = 2;
//     int v2 = 6;
//
//     Node* lcaNode = lca(root, v1, v2);
//
//     if (lcaNode != NULL)
//         // std::cout << "LCA of " << v1 << " and " << v2 << " is " <<
//         lcaNode->data << std::endl; std::cout << lcaNode->data << std::endl;
//     else
//         std::cout << "LCA not found" << std::endl;
//
//     return 0;
// }
/*
 You are given pointer to the root of the binary search tree and two values vl
and v2. You need to return the lowest common ancestor (LCA) of vl and 2 in the
binary search tree. In the diagram above, the lowest common ancestor of the
nodes 4 and 6 is the node 3. Node 3 is the lowest node which has nodes 4 and 6
as descendants.

Function Description

Complete the function Ica in the editor below. It should return a pointer to the
lowest common ancestor node of the two values given.

Ica has the following parameters:
- root: a pointer to the root node of a binary search tree
- V1: a node.data value
- 2: a node.data value

Input Format

The first line contains an integer, n, the number of nodes in the tree.
The second line contains n space-separated integers representing node. data
values. The third line contains two space-separated integers, vl and v2.

To use the test data, you will have to create the binary search tree yourself.
Constraints

1 ≤ n, node.data ≤ 5000
1 ≤ V1, v2 ≤ 5000
v1 # v2

The tree will contain nodes with data equal to v1 and v2.

Output Format
Return the value of the node that is the lowest common ancestor of v1 and v2.

Sample Input
6
423176
17

2 7

3

v1 = 1 and v2 = 7.

Sample Output

4

Explanation

LCA of 1 and 7 is 4, the root in this case.
Return a pointer to the node.
*/
