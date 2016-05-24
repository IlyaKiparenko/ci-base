#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <stack>
#include <queue>

using std::stack;
using std::queue;
using std::cout;

struct Node {
  int key;
  Node* left;
  Node* right;
};

Node* crN(int key_, Node* left_, Node* right_) {
  Node* t = new Node();
  t -> key = key_;
  t -> left = left_;
  t -> right = right_;
  return t;
}

Node* crTree(int n) {
  if (n > 1) {
    Node* root = new Node();
    int y = rand()%n;
    root -> key = rand()%20;
    root -> left = crTree(y);
    root -> right = crTree(n - 1 - y);
    return root;
  } else {
    if (n == 1)
      return crN(rand()%20, 0, 0);
    else
      return 0;
  }
}

void print1(Node* root) {
  // me -> left -> right
  stack<Node*> s;
  s.push(root);
  Node* t;
  while (!s.empty()) {
    t = s.top();
    cout << (t -> key) << " ";
    s.pop();
    if (t -> left != 0)
      s.push(t -> left);
    if (t -> right != 0)
      s.push(t -> right);
  }
  cout << "\n";
}

void print2(Node* root) {
  // left -> me -> right
  stack<Node*> s;
  stack<char> flag;
  s.push(root);
  flag.push(0);
  char f;
  Node* t;
  while (!s.empty()) {
    t = s.top();
    f = flag.top();
    if (f == 0) {
      flag.pop();
      flag.push(1);
      if (t -> right != 0) {
        s.push(t -> right);
        flag.push(0);
      }
    } else {
      cout << (t -> key) << " ";
      s.pop();
      flag.pop();
      if (t -> left != 0) {
        s.push(t -> left);
        flag.push(0);
      }
    }
  }
  cout << "\n";
}

void print3(Node* root) {
  // left -> right -> me
  stack<Node*> s;
  stack<char> flag;
  s.push(root);
  flag.push(0);
  char f;
  Node* t;
  while (!s.empty()) {
    t = s.top();
    f = flag.top();
    if (f == 0) {
      flag.pop();
      flag.push(1);
      if (t -> right != 0) {
        s.push(t -> right);
        flag.push(0);
      }
    } else {
      if (f == 1) {
        flag.pop();
        flag.push(2);
        if (t -> left != 0) {
          s.push(t -> left);
          flag.push(0);
        }
      } else {
        cout << (t -> key) << " ";
        flag.pop();
        s.pop();
      }
    }
  }
  cout << "\n";
}



int main() {
  srand(time(0));
  Node* root = crTree(13);
  print1(root);
  print2(root);
  print3(root);
  return 0;
}
