#ifndef SOLUTIONS_AVL_TREE_P_QUEUE_H_
#define SOLUTIONS_AVL_TREE_P_QUEUE_H_

class P_Queue {
 public:
  virtual void add(int key, int index) = 0;
  virtual int getRank(int index) = 0;
  virtual void changePriority(int newP, int index) = 0;
  virtual int min_pop() = 0;
  virtual int min_top() = 0;
};

#endif  // SOLUTIONS_AVL_TREE_P_QUEUE_H_
