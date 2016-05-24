#include "PHeap.h"
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <string>

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

void setE(Edge* c, int a_, int b_, int size_) {
  c -> a = a_;
  c -> b = b_;
  c -> size = size_;
}

struct Graph {
  int n_vertex;
  int m_edges;
  Edge* arr;
};

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

Graph* readG(std::string file_name) {
  FILE* f = fopen(file_name.c_str(), "r");
  Graph* t = new Graph;
  fscanf(f, "%i%i", &(t -> n_vertex), &(t -> m_edges));
  t -> arr = new Edge[t -> m_edges];
  int a, b, size_e;
  for (int i = 0; i < t -> m_edges; i++) {
    fscanf(f, "%i%i%i", &a, &b, &size_e);
    t -> arr[i].a = a - 1;
    t -> arr[i].b = b - 1;
    t -> arr[i].size = size_e;
  }
  return t;
}

struct Answ {
  int len;
  int count;
};

Answ Dijkstra(Graph* g, int start) {
  int* way = new int[g -> n_vertex];
  PHeap len_way(g -> n_vertex);
  int* count_way = new int[g -> n_vertex];
  for (int i = 0; i < g -> n_vertex; i++) {
    way[i] = start;
    len_way.push(INT_MAX, i);
    count_way[i] = 0;
  }
  way[start] = start;
  len_way.chg_rank(0, start);
  Edge e;
  int next;
  for (int i = 0; i < g -> n_vertex; i++) {
    int me = len_way.min_pop();
    for (int j = 0; j < g -> m_edges; j++) {
      e = g -> arr[j];
      if (e.a == me) {
        next = e.b;
      } else {
        if (e.b == me)
          next = e.a;
        else
          continue;
      }
      if (len_way.get_rank(next) > len_way.get_rank(me) + e.size) {
        len_way.chg_rank(len_way.get_rank(me) + e.size, next);
        count_way[next] = count_way[me] + 1;
        way[next] = me;
      } else {
          if ((len_way.get_rank(next) == len_way.get_rank(me) + e.size)
                    && (count_way[next] < count_way[me] + 1)) {
            len_way.chg_rank(len_way.get_rank(me) + e.size, next);
            count_way[next] = count_way[me] + 1;
            way[next] = me;
          }
      }
    }
  }
  Answ t;
  t.len = len_way.get_rank(g -> n_vertex - 1);
  t.count = count_way[g -> n_vertex - 1];
  return t;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    Answ right;
    char name_file[4];
    for (int number = 1; number < 20; number++) {
      _snprintf(name_file, sizeof(name_file), "%03i", number);
      printf("test %s\n", name_file);
      std::string path = "..\\roads_check\\";
      path = path + name_file;
      if (number < 16) {
        FILE* f = fopen((path + ".a").c_str(), "r");
        fscanf(f, "%i%i", &(right.len), &(right.count));
        fclose(f);
      }
      Graph* g = readG(path);
      Answ mine = Dijkstra(g, 0);
      if (number < 16)
        printf("\tRestricted Answer is %i %i\n", right.len, right.count);
      printf("\tMy Answer is %i %i\n", mine.len, mine.count);
    }
  } else {
    Graph test = {3, 2, 0};
    test.arr = new Edge[2];
    setE(test.arr + 0, 0, 1, 2);
    setE(test.arr + 1, 0, 2, 4);
    Answ mine = Dijkstra(&test, 0);
    printf("\tMy Answer is %i %i\n", mine.len, mine.count);
  }
  return 0;
}
