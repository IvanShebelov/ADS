// Copyright 2024 Ivan Shebelov

#ifndef LIB_DSU_DSU_H_
#define LIB_DSU_DSU_H_

class DSU {
    int _size;
    int* _parent;
    int* _rank;

public:
    DSU(int size = 0);
    ~DSU();
    void make_set(int elem);
    int find(int elem);
    void union_sets(int first, int second);
    void clear();
};

#endif  // LIB_DSU_DSU_H_