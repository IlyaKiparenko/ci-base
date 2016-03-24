#include "KSet.h"
#include "PHeap.h"
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <list>

struct Edge {
  int a;
  int b;
  int size;
};

Edge crE(int a_, int b_, int size_) {
  Edge c;
  c.a = a_;
  c.b = b_;
  c.size = size_;
  return c;
}

struct Graph {
  int n_vertex;
  int m_edges;
  Edge* arr;
};

int GFind(int i, int j, Graph* t, int len) {
  int u = 0;
  bool r = false;
  Edge q;
  do {
    q = t -> arr[u];
    u++;
    r = (q.a != i || q.b != j) && (q.a != j || q.b != i);
  } while (r && u < len);
  return !r;
}


Graph* crG(int n, int m) {
  Graph* g = new Graph;
  g -> n_vertex = n;
  g -> m_edges = m;
  g -> arr = new Edge[m];
  int a, b, size;
  for (int i = 0; i < m; i++) {
    do {
      if (i < n)
        a = i;
      else
        a = rand() % n;
      b = rand() % n;
    } while (a == b || GFind(a, b, g, i));
    size = rand() % 20;
    g -> arr[i] = crE(a, b, size);
  }
  return g;
}

void printG(Graph* t) {
  printf("Vertex = %i , Edges = %i\n", t -> n_vertex, t -> m_edges);
  Edge q;
  for (int i = 0; i < t -> m_edges; i++) {
    if (i % 3 == 0)
      printf("\n");
    q = t -> arr[i];
    printf("<%2i ~ %2i , %2i> ", q.a, q.b, q.size);
  }
  printf("\n");
}

Graph* Kruskal(Graph* g) {
  std::list<Edge> listE;
  PHeap heap(g -> m_edges);
  Edge t;
  KSet set(g -> n_vertex);
  for (int i = 0; i < g -> m_edges; i++) {
    heap.push(g -> arr[i].size, i);
  }
  for (int i = 0; i < g -> n_vertex; i++)
    set.add(i);
  for (int s = 0; s < g -> m_edges; s++) {
    t = g -> arr[heap.min_pop()];
    if (set.whereI(t.a) != set.whereI(t.b)) {
      set.merge(t.a, t.b);
      listE.push_back(t);
    }
  }
  set.print();
  Graph* r = new Graph;
  r -> n_vertex = g -> n_vertex;
  r -> m_edges = listE.size();
  r -> arr = new Edge[r -> m_edges];
  for (int i = 0; i < r -> m_edges; i++) {
    r -> arr[i] = listE.front();
    listE.pop_front();
  }
  return r;
}

int main() {
  srand(time(0));
  Graph* g = crG(5, 10);
  printG(g);
  printf("\n");
  Graph* res = Kruskal(g);
  printG(res);
  return 0;
}
