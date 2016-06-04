#include "AVL_Tree.h"
#include <queue>

unsigned char height(Node* p) {
  return p ? p -> height : 0;
}

int bfactor(Node* p) {
  return height(p->right) - height(p->left);
}

void fixheight(Node* p) {
  unsigned char hl = height(p->left);
  unsigned char hr = height(p->right);
  p->height = (hl > hr ? hl : hr) + 1;
}

Node* rotateright(Node* p) {
  Node* q = p->left;
  p->left = q->right;
  q->right = p;
  fixheight(p);
  fixheight(q);
  return q;
}

Node* rotateleft(Node* q) {
  Node* p = q->right;
  q->right = p->left;
  p->left = q;
  fixheight(q);
  fixheight(p);
  return p;
}

Node* balance(Node* p) {
  fixheight(p);
  if (bfactor(p) == 2) {
    if (bfactor(p->right) < 0)
      p->right = rotateright(p->right);
    return rotateleft(p);
  }
  if (bfactor(p) == -2) {
    if (bfactor(p->left) > 0)
      p->left = rotateleft(p->left);
    return rotateright(p);
  }
  return p;
}

Node* insert(Node* p, int k, int i) {
  if (!p)
    return new Node(k, i);
  if (k < p->key)
    p->left = insert(p->left, k, i);
  else
    p->right = insert(p->right, k, i);
  return balance(p);
}

Node* findmin(Node* p) {
  return p->left ? findmin(p->left) : p;
}

Node* removemin(Node* p) {
  if (p->left == 0) {
    Node* t = p->right;
    // delete p;
    return t;
  }
  p->left = removemin(p->left);
  return balance(p);
}

Node* find(Node* p, int k) {
  if (!p)
    return 0;
  if (k < p->key) {
    return find(p->left, k);
  } else {
    if (k > p-> key) {
      return find(p->right, k);
    } else {
      return p;
    }
  }
}

Node* remove(Node* p, int k, int index = -1) {
  if (!p)
    return 0;
  if (k < p->key) {
    p->left = remove(p->left, k, index);
  } else {
    if (k > p->key) {
      p->right = remove(p->right, k, index);
    } else {
      if (index != -1 && p->index == index) {
        Node* q = p->left;
        Node* r = p->right;
        delete p;
        if (!r)
          return q;
        Node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
      } else {
        p->right = remove(p->right, k, index);
        p->left = remove(p->left, k, index);
      }
    }
  }
  return balance(p);
}

AVL_Tree::AVL_Tree() {
  root = 0;
}

void AVL_Tree::add(int key, int index) {
  root = insert(root, key, index);
}

int AVL_Tree::del(int key, int index) {
  /*
  Node* t = remove(root, key, index);
  int u = t->index;
  delete t;
  return u;
  */
  root = remove(root, key, index);
  return 0;
}

int AVL_Tree::min_pop() {
  Node* t = findmin(root);
  int u = t->index;
  // delete t;
  root = removemin(root);
  return u;
}

int AVL_Tree::min_top() {
  Node* t = findmin(root);
  return t->index;
}

int AVL_Tree::getRank(int index) {
  std::queue<Node*>  g;
  int res = - 1;
  int index_m = 0;
  Node* t;
  g.push(root);
  do {
    t = g.front();
    g.pop();
    if (t != 0) {
      res = t->key;
      index_m = t->index;
      g.push(t->left);
      g.push(t->right);
    }
  } while (!g.empty() && (index_m != index));
  return (index_m != index) ? -1 : res;
}

void AVL_Tree::changePriority(int newP, int index) {
  int oldP = getRank(index);
  del(oldP, index);
  add(newP, index);
}

void delNode(Node* t) {
  if (t != 0) {
    delNode(t->left);
    delNode(t->right);
  }
  delete t;
}

AVL_Tree::~AVL_Tree() {
  delNode(root);
}
