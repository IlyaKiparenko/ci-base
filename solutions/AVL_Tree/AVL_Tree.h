#ifndef SOLUTIONS_AVL_TREE_AVL_TREE_H_
#define SOLUTIONS_AVL_TREE_AVL_TREE_H_

struct Node {
    int key;
    unsigned char height;
    Node* left;
    Node* right;
    Node(int k) {
      key = k;
      left = right = 0;
      height = 1;
    }
};


class AVL_Tree {
public:
  Node* root;

};
#endif  // SOLUTIONS_AVL_TREE_AVL_TREE_H_