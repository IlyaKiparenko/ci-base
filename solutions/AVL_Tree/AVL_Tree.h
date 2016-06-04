#ifndef SOLUTIONS_AVL_TREE_AVL_TREE_H_
#define SOLUTIONS_AVL_TREE_AVL_TREE_H_

#include "P_Queue.h"

struct Node {
  int key;
  int index;
  unsigned char height;
  Node* left;
  Node* right;
  explicit Node(int k, int i = 0) {
    key = k;
    index = i;
    left = right = 0;
    height = 1;
  }
};


class AVL_Tree : public P_Queue {
 public:
  Node* root;
  AVL_Tree();
  ~AVL_Tree();
  void add(int key, int index = 0);
  int del(int key, int index = -1);
  int min_pop();
  int min_top();
  void changePriority(int newP, int index);
  int getRank(int index);
};
#endif  // SOLUTIONS_AVL_TREE_AVL_TREE_H_
